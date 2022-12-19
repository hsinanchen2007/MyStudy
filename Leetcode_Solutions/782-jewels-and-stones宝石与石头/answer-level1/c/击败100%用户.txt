
```int numJewelsInStones(char * J, char * S){
    int n = 0;
    int a[58] = {0};
    int x = strlen(J);
    int y = strlen(S);
    int i = 0;
    for(;i < x; i++){
        a[J[i] - 'A']++;
    }

    for(i = 0; i < y; i++){
        if(a[S[i] - 'A'] > 0)
            n++;
    }
    return n;
}```
