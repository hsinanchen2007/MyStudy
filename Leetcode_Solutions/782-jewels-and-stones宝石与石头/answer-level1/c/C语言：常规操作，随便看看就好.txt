```
int numJewelsInStones(char * J, char * S){
    int a[128] = {0}, i, cnt = 0;
    
    for (i = 0; i < strlen(J); i++)
        a[J[i] - '0']++;
    for (i = 0; i < strlen(S); i++){
        if (a[S[i] - '0'] != 0)
            cnt++;
    }
    return cnt;
}
```
