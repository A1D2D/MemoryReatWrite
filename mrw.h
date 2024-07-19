#ifndef MRW_MEMORY_READ_WRITE_H
#define MEMORY_MEMORYREATWRITE_H
#include <iostream>
#include <vector>

namespace MRW {
   template<typename T>
   T readMemory(std::vector<char>& memory, int offsetInBytes = 0) {
      T t;
      int size = sizeof(T);
      if (offsetInBytes + size > memory.size()) {
         std::cerr << "read outOfBounds" << std::endl;
         return {};
      }
      memcpy(&t, memory.data() + offsetInBytes, size);
      return t;
   }

   template<typename T>
   std::vector<T> readMemoryArray(std::vector<char>& memory, int count, int offsetInBytes = 0) {
      int size = sizeof(T) * count;
      if (offsetInBytes + size > memory.size()) {
         std::cerr << "Array: read outOfBounds" << std::endl;
         return {};
      }
      std::vector<T> t(count);
      memcpy(t.data(), memory.data() + offsetInBytes, size);
      return t;
   }

   template<typename T>
   void writeMemory(std::vector<char>& memory, T value, int offsetInBytes = 0) {
      int size = sizeof(T);
      if (offsetInBytes + size > memory.size()) {
         memory.resize(offsetInBytes + size);
      }
      memcpy(memory.data() + offsetInBytes, &value, size);
   }

   template<typename T>
   void writeMemory(std::vector<char>& memory, const std::vector<T>& values, int offsetInBytes = 0) {
      int size = sizeof(T) * values.size();
      if (offsetInBytes + size > memory.size()) {
         memory.resize(offsetInBytes + size);
      }
      memcpy(memory.data() + offsetInBytes, values.data(), size);
   }
}

#endif //MEMORY_MEMORY_REAT_WRITE_H
