### 解题思路
看了前排大佬的解题思路，按正常思维会出现越位，long long int 也不行
num=num*2+A[i]换成num=num%10*2+A[i];

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    bool *returnA=(bool *)malloc(sizeof(bool)*(ASize));
    *returnSize=ASize;
    int i;
    long long int num=0;
    for(i=0;i<ASize;i++){
        num=(num%10)*2+A[i];
        if(num%5==0)returnA[i]=true;
        else returnA[i]=false;
    }
    return returnA;
}
```