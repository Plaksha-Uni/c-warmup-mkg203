#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

void csort_args(int n, char* argv[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
            if (strcmp(argv[i], argv[j]) > 0) {
                auto temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
}

void print(int n, char* argv[]) {
    for (int i = 0; i < n; i++) {
        printf("%c\n", *argv[i]);
    }
}

void print(int n, std::vector<std::string> argvec) {
    for(auto var : argvec) {
        std::cout << var << std::endl;
    }
}

int main(int argc, char* argv[]) {
    auto argvec = std::vector<std::string> (&argv[1], &argv[argc]);
    argv++;
    argc--;
    print(argc, argv);
    // print(argc, argvec);
    printf("csorting arguements\n");
    csort_args(argc, argv);
    print(argc, argv);

    printf("cppsorting arguements\n");
    std::sort(argvec.begin(), argvec.end());
    print(argc, argvec);
    return 0;
}
