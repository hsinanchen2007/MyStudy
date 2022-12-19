### 解题思路
此处撰写解题思路
先对每个数的因数做判断 ，注意平方数的因数为奇数
### 代码

```c
int yinshu(int n)
{
    if(n==1)
        return 0;
    int i=0; 
    int count=2;
    int tmp=1+n;
    int k=0;
    for( i=2;i*i<n;i++)
    {
        if(n%i==0)
        {
            k=i+n/i;
            tmp+=k;
            count+=2;
        }
    }
    if(i*i==n) //这是一个平方数，因数必为奇数，不满足条件
        return 0;
    if(count==4)
        return tmp;
    return 0;
}
int sumFourDivisors(int* nums, int numsSize){
    int ret=0;
    int tmp=0;
    for(int i=0;i<numsSize;i++)
    {
        tmp=yinshu(nums[i]);
        if(tmp>0)
            ret+=tmp;
    }
    if(ret>0)
        return ret;
    return 0;
}
```