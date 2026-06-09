### 解题思路
遍历字符串，栈中保存当前没有出现过的字符串的位置。
新字符来时去栈里找是否有满足条件的，有就跳过或替换。最终计算栈中字符串长度之和。

### 代码

```c
int FindIsIn(char *wordA, char *wordB) 
{
    int lenA = strlen(wordA);
    int lenB = strlen(wordB);

    while (lenB > 0 && lenA > 0) {
        lenA--;
        lenB--;
        if(wordA[lenA] != wordB[lenB]) {
            return false;
        }
    }
    return lenA >= lenB ? 1 : 2;    
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int codeSize[2000] = {0};
    int wordCount = 0;
    int isInclude = 0;
    int retSize = 0;

    if (wordsSize == 0) {
        return 0;
    }
    if (wordsSize == 1) {
        return strlen(words[0]) + 1;
    }
    for (int i = 0; i < wordsSize; i++) {
        // 查找是否已经在存在
        for (int j = 0; j < wordCount; j++) {           
            isInclude = FindIsIn(words[codeSize[j]], words[i]);
            //printf("check:%s is include words:%s return %d\n",words[codeSize[j]],words[i],isInclude);
            if (isInclude == 1) {
                break;
            }else if (isInclude == 2) {
                codeSize[j] = i;
                break;
            }
        }
        if(!isInclude) {
            codeSize[wordCount] = i;
            wordCount++;
        }
    }
    for (int i = 0; i < wordCount; i++) {
        retSize += strlen(words[codeSize[i]]) + 1;
    }
    return retSize;
}
```