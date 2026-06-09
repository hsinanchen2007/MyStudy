bool dp[MAX_LENGTH]，表示从index 0到i的子串能否拆分为多个单词。
从end index 0开始遍历到结尾，如果子串的尾部能够匹配到字典中的某个单词，则再判断子串余下部分的dp是否也为TRUE，如果未TRUE则表示该子串也可以拆分。

```
#define MAX_LENGTH  (200)

bool isStrEndWith(char *s, int endIdx, char *wordDict, int *left)
{
    int wordDictLen = strlen(wordDict);
    int stringLen = endIdx + 1;
    
    if (wordDictLen > stringLen) {
        return false;
    }
    
    if (strncmp(s + stringLen - wordDictLen, wordDict, wordDictLen) == 0) {
        *left = stringLen - wordDictLen;
        
        return true;
    }
    
    return false;
}

bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
    bool dp[MAX_LENGTH] = {0};   //从index 0到i的字符串能否拆分为多个单词    
    int stringLen = strlen(s);
    
    if (stringLen > MAX_LENGTH) {
        printf("ERROR: stringLen %d\n", stringLen);
        return;
    }
    
    for (int i = 0; i < stringLen; i++) {
        //和字典中的每个单词比较，判断是否以它结尾
        for (int j = 0; j < wordDictSize; j++) {
            int left = 0;
            if (isStrEndWith(s, i, wordDict[j], &left)) {                
                if (left == 0 || dp[left - 1] == 1) {
                    //没有剩余字符，或者剩余的字符串也可以拆分，则退出
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    
    return dp[stringLen - 1];
}
```
