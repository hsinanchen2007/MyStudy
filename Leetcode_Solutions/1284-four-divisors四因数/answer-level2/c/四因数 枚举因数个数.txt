对每个元素进行的因数进行枚举，除了自身和1之后，如果仅能找到两个因数就符合要求。
因数查找时只判断小于sqrt(num)的部分，如果能找到一个因素a，那么大于sqrt(num)可能会有一个对应因素b满足a*b=num
如果num是平方数，那么因数个数就为奇数，不符合要求。


```
int get_least(int num)
{
    int res = -1;
    bool get_lease = false;
    int i = 2;
    for( i = 2; i * i < num; i++)
    {
        if(num % i == 0)
        {
            if(res != -1)
                return -1;
            res = i;
        }
    }
    if(i * i == num)
        return -1;
    return res;
}

int sumFourDivisors(int* nums, int numsSize){
    int *tmp = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++)
    {
        tmp[i] = get_least(nums[i]);
    }
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(tmp[i] != -1)
        {
            sum += 1;
            sum += nums[i];
            sum += tmp[i];
            sum += nums[i] / tmp[i];
        }
    }
    return sum;
}
```
