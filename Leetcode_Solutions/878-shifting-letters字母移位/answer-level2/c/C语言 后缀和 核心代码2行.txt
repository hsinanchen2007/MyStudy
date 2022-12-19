```
char * shiftingLetters(char * S, int* shifts, int shiftsSize){
    for (int i = shiftsSize - 1; i >= 0; i--) {
        if (i != shiftsSize - 1) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }
        S[i] = 'a' + (S[i] - 'a' + shifts[i]) % 26; 
    }
    return S;
}
```
