### 解题思路
循环嵌套
第一个循环遍历所有整数
第二个循环统计每个整数的位数

### 代码

```c
int findNumbers(int* nums, int numsSize){
    int result=0;
    int i=0;
    while(i<numsSize)
    {
        int num=nums[i];
        int bit=0;
        while(num!=0)
        {
            num/=10;
            ++bit;
        }
        if(bit%2==0)
            ++result;
        ++i;
    }
    return result;
}
```