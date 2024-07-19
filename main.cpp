#include <iostream>
#include <vector>

#include "mrw.h"

struct Vector {
   float x = 0;
   float y = 0;
   float z = 0;
};

int main() {
   std::vector<char> buffer;

   // "Allocating" memory for 3 Vectors
   int vecSize = sizeof(Vector) * 3;
   buffer.resize(vecSize);

  
   std::vector<Vector> samples {
      {5,5,3},
      {4,2,3},
      {2,5,3}
   };
   //write samples into the buffer
   MRW::writeMemory(buffer,samples);

   //read a Vector from buffer
   Vector vec = MRW::readMemory<Vector>(buffer, 0);
   std::cout << "vec: " << vec.x << ", " << vec.y << ", " << vec.z << std::endl;

   //read the 3 Vector from buffer
   Vector vec1 = MRW::readMemory<Vector>(buffer, sizeof(Vector)*2);
   std::cout << "vec: " << vec1.x << ", " << vec1.y << ", " << vec1.z << std::endl;

   //read all 3 Vectors from the buffer
   std::vector<Vector> vecs = MRW::readMemoryArray<Vector>(buffer, 3, 0);
   for (Vector& vector : vecs) {
      std::cout << "vec: " << vector.x << ", " << vector.y << ", " << vector.z << std::endl;
   }
  
}
