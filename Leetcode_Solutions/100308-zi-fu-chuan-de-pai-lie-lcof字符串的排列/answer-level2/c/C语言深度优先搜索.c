[根据这位的`C++`版本改编](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/c-dfs-mian-shi-ti-38-zi-fu-chuan-de-pai-lie-by-yue/)
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char* s, int pos, char** re, int* returnSize){
    int len = strlen(s);
    if(pos == len){ // 当pos指向s的最后一位
        re[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
        strcpy(re[*returnSize], s);
        *returnSize += 1;
        return;
    }
    for(int i = pos; i < len; ++i){
        // 首先判断当前元素是否重复并已被使用过
        bool prune = false;
        for(int j = pos; j < i; ++j){
            if(s[j] == s[i]){
                prune = true;
                break;
            }
        }
        if(prune == true){
            continue;
        }

        char temp = s[pos];
        s[pos] = s[i];
        s[i] = temp;

        dfs(s, pos + 1, re, returnSize);

        temp = s[i];
        s[i] = s[pos];
        s[pos] = temp;
    }
    return;
}
char** permutation(char* s, int* returnSize){
    int len = strlen(s);
    int maxSize = 1;

    while(len > 1){ // maxSize保存最多有多少种排列方法
        maxSize *= len;
        len--;
    }

    char** re = (char**)malloc(maxSize * sizeof(char*));

    *returnSize = 0;

    dfs(s, 0, re, returnSize);

    re = (char**)realloc(re, (*returnSize) * sizeof(char*)); // 将多余的空间释放

    return re;
}
```
