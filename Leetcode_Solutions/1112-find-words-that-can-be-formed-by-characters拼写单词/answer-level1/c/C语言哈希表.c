### 解题思路
分别对每行取哈希表，与参考哈希表比较，满足条件的话记录长度

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    
    int hash2[26] = {0};
    int len2 = strlen(chars);
    int len1;
    int i, j;
    int num = 0;
    
    for(i = 0; i < len2; i++) {
        hash2[chars[i] - 'a']++;
    }
    
    for(i = 0; i < wordsSize; i++) {
        int hash1[26] = {0};
        len1 = strlen(words[i]);
        for(j = 0; j < len1; j++) {
            hash1[words[i][j] - 'a']++;
        }
        for(j = 0; j < 26; j++) {
            if(hash1[j] > hash2[j]) {
                break;
            }
        }
        if(j == 26) {
            num += len1;
        }
    }
    return num;
}
```