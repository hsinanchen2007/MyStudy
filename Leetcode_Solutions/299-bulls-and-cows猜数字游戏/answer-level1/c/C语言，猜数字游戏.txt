思路：
1. 遍历secret，找公牛（同位相等），并把可能的母牛出现次数全都记录到map中
2. 遍历guess，只找母牛（同位不等且map中有次数），每找到一只对应map减1  
3. 打印成字符串

```C
char * getHint(char * secret, char * guess){
    int A = 0, B = 0, map[10] = {0};
    for (int i=0; secret[i]; i++)  
        if (secret[i] == guess[i]) A++;
        else map[secret[i]-'0']++;
    for (int i=0; guess[i]; i++)
        if (map[guess[i]-'0'] && secret[i] != guess[i]) {
            B++;
            map[guess[i]-'0']--;
        }
    char* res = (char*)malloc(sizeof(char)*10);
    sprintf(res, "%dA%dB", A, B);
    return res;
}
```
