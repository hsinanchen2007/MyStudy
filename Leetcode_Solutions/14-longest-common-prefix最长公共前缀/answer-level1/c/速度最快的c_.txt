# 首先吐槽一下 LeetCode 的执行用时和内存消耗并不稳定, 见以下数据
![11.png](https://pic.leetcode-cn.com/e9ff809ab2d4eecb1e245780f56240f158cde83fe708dacabbe7c0dc3e5a223b-11.png)



上面4个是相同的代码哦, 如果不是有个 0ms 让我骄傲了也不会写这个

1. 由于个人能力有限, 觉得不管如何花里胡哨, 必然会有两个循环
    - 1.遍历字符串数组
    - 2.遍历字符串
2. 大体思路: 
    - 1.特殊情况处理:字符串数组为空, 返回"", 字符串数组长度为1,直接返回第一个字符串
    - 2.取第一个字符串作为标准, 其他字符串和它比较
3. 两种遍历模式:
    - a.注释掉的代码, 从标准串的第一个字符开始, 每个字符串都跟它比较, 有一个不同则返回
    - b.依次遍历每个字符串, 逐步缩小最长公共字符串的长度

```
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) 
        return "";
        
    if (strsSize == 1)
        return strs[0];
    
    int i = 0, j = 0;
    int len = strlen(strs[0]);
    char *ret = malloc(len + 1);
    strcpy(ret, strs[0]);
    
    for (i = 1; i < strsSize; i++) {
        for (j = 0; j < len; j++) {
            if (strs[i][j] != ret[j]) {
                len = j;
                break;
            }
        }
        if (len == 0)
            return "";
    }
    
    // for (j = 0; j < len; j++) {
    //     for (i = 1; i < strsSize; i++) {
    //         if (strs[i][j] != ret[j])
    //             goto err;
    //     }
    // }

err:
    ret[j] = '\0';
    return ret;
}
```


