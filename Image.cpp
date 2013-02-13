/**
 * Image.cpp
 *	
 */
  
#include "Image.h"


Image::Image(char aPath[]){
	//Constructor Stub
}

int Image::getHeight(){
	return height;
}

int Image::getWidth(){
	return width;
}

void Image::saveAsPixelMap(char aPath[]){
	
	std::ofstream myfile;
	myfile.open(aPath);
	
	myfile << "P3\n" << this->getWidth() <<" "<< this->getHeight() <<"\n255\n";
	std::vector < Pixel* > row;
	for (int y = 0; y < this->getHeight(); y++){
		row = imageData.at(y);
		for (int x = 0; x < this->getWidth(); x++){
            
			myfile << row.at(x)->getRed() << " ";
			myfile << row.at(x)->getGreen() << " ";
			myfile << row.at(x)->getBlue() << " ";
			
            
		}
	}
	std::cout << "\n Writing File to " << aPath << "\n \n";
	myfile.close();
}

