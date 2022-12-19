### 解题思路
看了题解，这个思路真的巧妙，学到了。
之前用交换位置的方法，后来后面换了前面就会乱。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
    int a=0;
    int b=strlen(S);
    int n=b;
    int* num=(int*)malloc(sizeof(int)*(strlen(S)+1));
    for(int i=0;i<strlen(S);i++)
    {
        if(S[i]=='I')
        num[i]=a++;
        else
        num[i]=b--;
    }
    if(a==b)
    num[n]=a;
    *returnSize=strlen(S)+1;
    return num;
}
```