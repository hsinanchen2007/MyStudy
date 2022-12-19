// 如果a是b的前身，返回1,反之返回0
int IsPreWord(char *a, char *b) 
{
    int i = 0;
    int j = 0;    

    if (strlen(a) + 1 != strlen(b)) {
        return 0;
    }

    while (i < strlen(a) && j < strlen(b)) {
        if (a[i] == b[j]) {
            j++;
            i++;
            continue;
        }
        if (a[i] != b[j]) {            
            j++;            
        }
    }
    if (i != strlen(a)) {
        return 0;
    }
    return 1;
}

int longestStrChain(char ** words, int wordsSize){
    char* temp;
    int i;
    int j;
    int *dp;
    int ret = 0;

    if (words == NULL) {
        return 0;
    }
    if (wordsSize < 1) {
        return 0;
    } 

    // 冒泡排序，按长度升序排列
    for (i = 0; i < wordsSize; ++i) {
        for (j = i + 1; j < wordsSize; ++j) {
            if (strlen(words[i]) > strlen(words[j])) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    /** debug
    for (i = 0; i < wordsSize; ++i) {
        printf("%s ",words[i]);
    }
    */

    dp =(int *)malloc((wordsSize)*sizeof(int));
    // dp[i] 表示 到 words[i] 为止最长的词链长度, 初始化默认只有自身一个单词链
    for (i = 0; i < wordsSize; ++i) {
        dp[i] = 1;
    }
    // 如果单词 word[i] 是word[j]的前身，那么word[j] = max(dp[j],dp[i]+1)
    for (i = 0; i < wordsSize-1; ++i) {        
        for (j = i + 1; j < wordsSize; ++j) {
            if (IsPreWord(words[i],words[j]) && dp[i] >= dp[j]) {               
                dp[j] = dp[i] + 1;
            }
        }        
    }
    // 从dp[]中选出最大值，即最长字符串链
    for (i = 0; i < wordsSize; ++i) {
        // printf("dp[%d]=%d\n", i, dp[i]);
        if (ret < dp[i]) {
            ret = dp[i];
        }
    }
    return ret;
}

