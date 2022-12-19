### 解题思路
很简单的思路了，每次移动1步，移动k次...

### 代码

```java
/**
    向右移动k位置，即向右移动1步重复k次
*/

class Solution
{
    public void rotate(int[] nums, int k)
    {
        if(nums.length > 1)
        {
            for(int i = 0; i < k; i++)
            {
                rotateSingleStep(nums);
            }
        }
    }
    
    void rotateSingleStep(int[] nums)
    {
        int tmp = nums[nums.length - 1];
        
        for(int i = nums.length - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        
        nums[0] = tmp;
    }
}
```