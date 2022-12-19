```
int numJewelsInStones(char * J, char * S){
    int hashTable[128] = {0};
    int lengthofJ = strlen(J);
    int lengthofS = strlen(S);
    int res = 0;
    for(int i = 0; i < lengthofJ; i++) {
        hashTable[J[i]] =  1;
    }
    for(int i = 0; i < lengthofS; i++) {
        res += hashTable[S[i]];
    }
    return res;
}
```
