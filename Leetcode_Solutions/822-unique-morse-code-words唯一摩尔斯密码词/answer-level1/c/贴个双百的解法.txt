把单词对应的摩斯码当做二进制数处理，转化成十进制数比大小，减少比较开销。



```
int uniqueMorseRepresentations(char ** words, int wordsSize){
    if (wordsSize == 0){
        return 0;
    }
    int value[26] = {1,8,10,4,0,2,6,0,0,7,5,4,3,2,7,6,13,2,0,1,1,1,3,9,11,12};
    int len[26] = {2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4};
    int multi[26] = {4,16,16,8,2,16,8,16,4,16,8,16,4,4,8,16,16,8,8,2,8,16,8,16,16,16};
    int lenWords[100] = {0};
    long num[100] = {0};
    long gap[100] = {0};
    int lenTmp, numGap = 0, numDiff = 1, flag = 0;
    for(int i = 0; i < wordsSize; i++){
        lenTmp = strlen(words[i]);
        for (int j = 0; j < lenTmp; j++){
            num[i] = num[i]*multi[words[i][j] - 'a'] + value[words[i][j] - 'a'];
            lenWords[i] += len[words[i][j] - 'a'];
        }
    }
    for (int i = 1; i < wordsSize; i++){
        if (num[i] != num[0]){
            flag = 0;
            gap[numGap] = num[i] - num[0];
            for (int j = 0; j < numGap; j++){
                if (gap[numGap] == gap[j]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                numGap++;
            }
        }
    }   
    return numGap + 1;
}
```
