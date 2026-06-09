### 解题思路
数出每个element有几位数，判断数字的数目是否为偶数，若是，则`count++`即可

### 代码

```c
int findNumbers(int* nums, int numsSize){
    int count=0;
    for (int i=0 ; i<numsSize ; i++)
    {
        int digit=0;
        do
        {
            nums[i]/=10;
            digit++;
        } while(nums[i]!=0);
        if (digit%2==0)
            count++;
    }
    return count;
}
```