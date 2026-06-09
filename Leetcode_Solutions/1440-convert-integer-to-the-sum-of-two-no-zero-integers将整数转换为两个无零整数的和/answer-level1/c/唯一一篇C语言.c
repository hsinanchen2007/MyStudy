### 解题思路
算法很渣，略过。
returnSize需要指定，返回的指针是不知道具体多少位的，故*returnSize=2;

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool check(int x)
{
    if(x==0) return false;
    while(x)
    {
        if(x%10==0) return false;
        x/=10;
    }
    return true;
}
int* getNoZeroIntegers(int n, int* returnSize){
    *returnSize=2;
    int * a=malloc(sizeof(int)*2);
    for(int i=1;i<n;i++)
    {
        int j=n-i;
        if(check(i)&&check(j))
        {
            a[0]=i,a[1]=j;
            return a;
        }
    }
    a[0]=a[1]=-1;
    return a;
}
```