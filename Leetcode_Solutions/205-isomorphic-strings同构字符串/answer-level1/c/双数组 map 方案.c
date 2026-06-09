``` c
/*
* two maps 
* 
*  map[a] -> b
*  map[b] -> a
*
*/

bool isIsomorphic(char * s, char * t){
    char A[128] = { 0 };
    char B[128] = { 0 };
    while(*s != '\0') {
        if(A[*s] != 0 ) {
            if(A[*s] != *t) return 0;
        } else {
            A[*s] = *t;
        }
        if(B[*t] != 0) {
            if(B[*t] != *s) return 0;
        } else {
            B[*t] = *s;
        }
        s++;
        t++;
    }
    return 1;
}
```