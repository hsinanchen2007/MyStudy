![双100.jpg](https://pic.leetcode-cn.com/a6e1dd8f18d49898adaf1d567c2119856552827e3da89d398633e7f6482917e7-%E5%8F%8C100.jpg)

思路：
只有小写字母，因此长26的数组存hash计数就可以了。
chars字符遍历，hash值++
words遍历，每个字符串字符遍历，拷贝个临时hash，每个计数--就可以了，=0直接break出去。

代码：
```
#define HASH_SIZE (26)
#define GET_HASH_SUB(val) ((val) % HASH_SIZE)

int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[HASH_SIZE];
    int tmpHash[HASH_SIZE];
    int len = 0;
    char *pChar = chars;
    int retLen = 0;
    int sub = 0;

    if(NULL == words
        || 0 == wordsSize
        || NULL == chars
        || 0 == strlen(chars)){
        return 0;
    }

    memset(hash, 0, sizeof(hash));
    while(*pChar != '\0'){
        hash[GET_HASH_SUB(*pChar)]++;
        pChar++;
    }

    for(int i = 0; i < wordsSize; i++){
        memcpy(tmpHash, hash, sizeof(hash));
        pChar = words[i];
        len = 0;
        while(*pChar != '\0'){
            sub = GET_HASH_SUB(*pChar);
            if(0 == tmpHash[sub]){
                break;
            }
            tmpHash[sub]--;
            pChar++;
            len++;
        }
        if(*pChar == '\0'){
            retLen += len;
        }
    }
    
    return retLen;
}
```

