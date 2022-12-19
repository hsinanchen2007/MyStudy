```
int CharPriv[26];
int cmp(void *a, void *b) 
{
    int aindex = *((char*)a) - 'a';
    int bindex = *((char*)b) - 'a';
    return (CharPriv[bindex] - CharPriv[aindex]);
}
char * customSortString(char * S, char * T)
{
    memset(CharPriv, 0, 26*sizeof(int));
    int len = strlen(S);
    int lenT = strlen(T);
    int index = 0;
    int sindex = 0;
    int priv = 26;
    for (index = 0; index < len; index++) {
        sindex = S[index] - 'a';
        CharPriv[sindex] = priv;
        priv--;
    }
    qsort(T, lenT, sizeof(char), cmp);
    return T;
}
```
