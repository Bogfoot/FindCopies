#include "Walk.h"

void printSVec(svec &files) {
  for (const auto &file : files) {
    std::cout << file << std::endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Usage:\n"
              << "\t" << argv[0] << " [Source directory] [Target directory]"
              << std::endl;
    return 1;
  } else if (argc == 2) {

    std::cout << "Usage:\n"
              << "\t" << argv[0] << " [Source directory] [Target directory]"
              << std::endl;
    std::cout << "\tYou're either missing the [Source directory] or [Target "
                 "directory]."
              << std::endl;
    return 2;
  } else if (argc > 3) {
    std::cout << "Usage:\n"
              << "\t" << argv[0] << " [Source directory] [Target directory]"
              << std::endl;
    std::cout << "\tFlags are not yet supported." << std::endl;
    return 3;
  }

  svec inFiles, outFiles, Copies;
  std::string inPath = argv[1], outPath = argv[2];
  std::thread w1(FindCopies, inPath, std::ref(inFiles), outPath,
                 std::ref(outFiles), std::ref(Copies));
  std::thread w2(spin);
  /* FindCopies(inPath, inFiles, outPath, outFiles, Copies); */
  /* spin(); */

  if (Copies.size() == 0)
    std::cout << "No copies were found." << std::endl;
  else if (Copies.size() == 1 && Copies[0] == "Failed.") {
  } else {
    printSVec(Copies);
  }
}
