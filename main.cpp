#include "pixel.h"   
#include <iostream>  
#include <fstream>   
#include <sstream>   
#include <vector>    
#include <string>    

// Function to calculate the average RGB
void average_colors(const std::vector<Pixel>& pixelList)
{
    float totalR = 0.0f, totalG = 0.0f, totalB = 0.0f;  // Initialize RGB values
    for (int i = 0; i < pixelList.size(); i++) // loop through all pixels and sum up their RGB values
    {
        totalR += pixelList[i].r;  // Add red value
        totalG += pixelList[i].g;  // Add green value
        totalB += pixelList[i].b;  // Add blue value
    }
    // divide totals by number of pixels
    float avgR = totalR / pixelList.size();
    float avgG = totalG / pixelList.size();
    float avgB = totalB / pixelList.size();

    // Print average values
    std::cout << "Average R: " << avgR << std::endl;
    std::cout << "Average G: " << avgG << std::endl;
    std::cout << "Average B: " << avgB << std::endl;
}
// Function to flip pixels vertically
void flip_vertically(std::vector<Pixel>& pixelList)
{
    int maxY = 256;  // 256 y limit

    // Loop through pixels and flip their y coordinate
    for (int i = 0; i < pixelList.size(); i++)
    {
        pixelList[i].y = maxY - 1 - pixelList[i].y;  // Flip the y value
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string filename = argv[1]; // Get the filename from the command line
    std::vector<Pixel> pixelList; // Create a vector to stor pixels
    std::ifstream file(filename); // Open the file for reading
    if (!file.is_open())  // If the file cannot be opened, print an error
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))  // Read file line by line
    {
        std::stringstream ss(line);   // Create a stringstream
        Pixel pixel;                  // Create a pixel object to hold data
        std::string value;            // Temporary variable for each value

        // Get the x value
        std::getline(ss, value, ',');
        pixel.x = std::stoi(value);  // Convert string to integer for x

        // Get the y value
        std::getline(ss, value, ',');
        pixel.y = std::stoi(value);  // Convert string to integer for y

        // Get the red (r) value
        std::getline(ss, value, ',');
        pixel.r = std::stof(value);  // Convert string to float for red

        // Get the green (g) value
        std::getline(ss, value, ',');
        pixel.g = std::stof(value);  // Convert string to float for green

        // Get the blue (b) value
        std::getline(ss, value, ',');
        pixel.b = std::stof(value);  // Convert string to float for blue

        // Add the pixel to the vector
        pixelList.push_back(pixel);
    }

    file.close();
    average_colors(pixelList);
    flip_vertically(pixelList);

    std::ofstream flippedFile("flipped.dat"); // Open a file to write the flipped data
    if (!flippedFile.is_open())  // If the file can't be created, print an error
    {
        std::cerr << "Error creating file: flipped.dat" << std::endl;
        return 1;
    }
    for (int i = 0; i < pixelList.size(); i++) // Write pixel data to the flipped file
    {
        flippedFile << pixelList[i].x << "," << pixelList[i].y << "," 
                    << pixelList[i].r << "," << pixelList[i].g << "," 
                    << pixelList[i].b << "\n";
    }
    flippedFile.close();  // Close the output file after writing
    std::cout << "Flipped data written to flipped.dat" << std::endl; //letuser know that the flipped data was written

    return 0;
}