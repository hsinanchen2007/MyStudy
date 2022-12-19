### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 bool isDiv(int num);
int* selfDividingNumbers(int left, int right, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*(right-left+1));
    *returnSize=0;

    for(int i=left;i<=right;i++)
    {
        if(isDiv(i))
            res[(*returnSize)++]=i;
    }
    return res;
}

bool isDiv(int num)
{   
    int temp=num;
    while(temp>0)
    {
        int n;
        if(temp>=10)
            n=temp%10;
        else
            n=temp;
        if(n==0||num%n!=0)
            return false;
        temp/=10;
    }
    return true;
}
```