```
void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
char * reverseStr(char * s, int k){
    int l = strlen(s);
    for(int i = 0; i < l; i += 2*k)
    {
        int h;
        int low = i;
        if(l - i <= k)h = l - 1;
        else h = i + k - 1;
        while(low < h){
            swap(&s[low++], &s[h--]);
        }

    }
    return s;
}
```
