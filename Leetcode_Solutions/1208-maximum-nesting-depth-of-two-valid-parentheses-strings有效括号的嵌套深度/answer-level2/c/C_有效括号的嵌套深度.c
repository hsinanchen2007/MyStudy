### 解题思路
没看懂题目在说啥，参考题解
https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/lajiti-mu-by-jzns7jsmj6/
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int length=0;
    for(int i=0;seq[i]!='\0';++i)++length;
    int* result=(int*)malloc(sizeof(int)*length);

    int depth=0;
    for(int i=0;i<length;++i)
    {
        if(seq[i]=='(')
            result[i]=depth++;
        if(seq[i]==')')
            result[i]=--depth;
        result[i]%=2;
    }
    *returnSize=length;
    return result;
}

```