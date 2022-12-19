```
int longestPalindrome(char * s){
    int i, len, index, *hash = (int*)calloc(52, sizeof(int));
    for(i = 0;i < strlen(s);i ++){
        index = (s[i] >= 'a' ? s[i] - 'a' + 26 : s[i] - 'A');
        hash[index] ++;
    }
    bool flag;
    for(i = 0, len = 0, flag = 0;i < 52;i ++)
        if(hash[i] % 2 == 0)
            len += hash[i];
        else if (flag == 0){
            len += hash[i];
            flag = 1;
        }
        else
            len += hash[i] - 1;
    free(hash);
    return len;
}
```
