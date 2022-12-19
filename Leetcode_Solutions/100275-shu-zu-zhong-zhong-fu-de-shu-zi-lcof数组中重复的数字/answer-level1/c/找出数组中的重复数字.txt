### 解题思路
数组nums中有numsize个数字，申请一个长度为numsize的数组hashmap，初始值全部为0。
逐个去取nums中数字nums[i],并置hashmap中的nums[i]的位置+1，如果hashmap[nums[i]]>1,则该数字重复。

### 代码

```c
int findRepeatNumber(int *nums, int numsize)
{
    int hashMap[numsize];
    for(int i=0; i< numsize; i++)
    {
        hashMap[i]=0;
    }
    for (int i=0; i<numsize; i++)
    {
        hashMap[nums[i]]++;
        if(hashMap[nums[i]] > 1)
            return nums[i];
    }
    return 0;
}
```