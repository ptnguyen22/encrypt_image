/*
Peter Nguyen
PhotoMagic.cpp - Program that takes in command line arguments to
                 manipulate an image by changing each pixel color.
                 It uses the FibLFSR from previous assignment and
                 a seed from a command line argument to generate
                 pseudo-random numbers that is then used to manipulate
                 the pixel colors. It saves the encrypted image to
                 an output file from command line argument and
                 also uses SFML to display 2 windows for the original 
                 image and encrypted image.
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "FibLFSR.h"
#include <iostream>


using namespace std;

void transform(sf::Image& img, FibLFSR* fib);

int main(int argc, char** argv){

    //Create a FibLFSR from command line argument at index 3
    FibLFSR start(argv[3]);
    FibLFSR* seed=&start;

    //Load image from command line argument at index 1
    sf::Image image;
    if (!image.loadFromFile(argv[1]))
		  return -1;

    //Create window objects
    sf::Vector2u size = image.getSize();

    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted");

    //Create a sprite with original image
    sf::Texture text;
    text.loadFromImage(image);
    sf::Sprite orig;
    orig.setTexture(text);

    transform(image, seed);

    //Create a sprite from encrypted image
    //Create a sprite with original image
    sf::Texture text2;
    text2.loadFromImage(image);
    sf::Sprite encrypted;
    encrypted.setTexture(text2);

    //Save transformed image to file named at index 2 from command line argument
    if (!image.saveToFile(argv[2]))
		  return -1;

    //SFML window loop to display original and encrypted image
    while (window1.isOpen() && window2.isOpen()) {
      sf::Event event;
      while (window1.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        window1.close();
      }
      while (window2.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        window2.close();
      }
      //Clear, draw, and display both windows using the sprites made from 
      //textures from the images
      window1.clear();
      window1.draw(orig);
      window1.display();
      window2.clear();
      window2.draw(encrypted);
      window2.display();
      }
}

//Function with image and FibLFSR arguments
//that transform the image using psuedo-random numbers
//generated from FibLFSR
void transform(sf::Image& img, FibLFSR* fib){
    //Color variable for pixel
    sf::Color c;

    //Get size of image
    sf::Vector2u size = img.getSize();

    for (int x = 0; x<size.x; x++) {
		  for (int y = 0; y<size.y; y++) {
        //Get color of pixel at x, y
			  c=img.getPixel(x,y);

        //Set the rgb values by xor current values
        //with a newly generated 8 bit int
        c.r=c.r^fib->generate(8);

        c.g=c.g^fib->generate(8);

        c.b=c.b^fib->generate(8);

        //Set new pixel color at coord x,y
        img.setPixel(x,y,c);
		}
	}
}
