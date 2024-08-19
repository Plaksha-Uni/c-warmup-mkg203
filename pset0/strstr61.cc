#include <cstring>
#include <cassert>
#include <cstdio>

char* mystrstr(const char* s1, const char* s2) {                                         
    if (s1[0] == '\0') {
        return (char *) s1;
    }
    for (auto i = 0; s1[i] != '\0'; i++) {
        int check = 0;
        if (s1[i] == s2[0]) {
            for (auto j = 0; s2[j] != '\0'; j++) {
                if (s2[j] != s1[i+j] && s2[j] != 0 && s1[i+j] != 0) {
                    break;
                }
                check = j + 1;
            }
        }
        if (s2[check] == '\0') {
            return (char *) &s1[i];
        }
    }
    return nullptr;                                                                      
}                                                                                        

char* mystrstr_ptr(const char* s1, const char* s2) {                                         
    if (*s1 == '\0') {
        return (char *) s1;
    }
    for (auto i = 0; *(s1+i) != '\0'; i++) {
        int check = 0;
        if (*(s1+i) == *s2) {
            for (auto j = 0; *(s2+j) != '\0'; j++) {
                if (*(s2+j) != *(s1+i+j) && *(s2+j) != 0 && *(s1+i+j) != 0) {
                    break;
                }
                check = j + 1;
            }
        }
        if (*(s2+check) == '\0') {
            return (char *) &*(s1+i);
        }
    }
    return nullptr;                                                                      
}                                                                                        
                                                                                             
int main(int argc, char* argv[]) {                                                       
    assert(argc == 3);                                                                   
    printf("strstr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], strstr(argv[1], argv[2]));                      
    printf("mystrstr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], mystrstr(argv[1], argv[2]));                                
    assert(strstr(argv[1], argv[2]) == mystrstr(argv[1], argv[2]));                      
    printf("mystrstr_ptr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], mystrstr_ptr(argv[1], argv[2]));                                
}
