![捕获.PNG](https://pic.leetcode-cn.com/c1e5fa449fb6021cbf15736b63d89893ed37a02627ac98033f94e31849f6accf-%E6%8D%95%E8%8E%B7.PNG)


思路方法：循环，一个一个字母比较

代码如下

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 1)
        return strs[0];
    char *p = NULL;
    int i, j = 0;

    for (i = 0; i < strsSize && strs[i][j] != '\0'; ++i)
    {
        if (strs[i][j] != strs[i+1][j])
            break;
        if (i == strsSize-2) {
            i = -1;         //第一个字母比较完了，从头开始比第二个
            ++j;
        }
    }

    p = (char *)malloc(sizeof(char) * (j+1));

    for (i = 0; i < j; ++i)
        p[i] = strs[0][i];
    p[i] = '\0';

    return p;
}