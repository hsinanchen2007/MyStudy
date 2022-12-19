### 解题思路
定义变量zeroTime记录遇到的0的次数，默认0

遍历第一角标到(长度-zeroTime)的元素，找到0就将0之后的元素全部往前1位，然后将(长度-zeroTime)位置的元素置为0

由于可能遇到连续几个角标都为0的情况，所以需要加一个判断：在当前角标不为0之前，都不往后遍历

### 代码
```java
class Solution
{
    public void moveZeroes(int[] nums)
    {
        int zeroTime = 0;
        
        for(int i = 0; i < nums.length - zeroTime;)
        {
            if(nums[i] == 0)
            {
                for(int j = i; j < nums.length - zeroTime - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                nums[nums.length - 1 - zeroTime] = 0;
                zeroTime++;
            }
            if(nums[i] != 0)
            {
                i++;
            }
        }
    }
}
```