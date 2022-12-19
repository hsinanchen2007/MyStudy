### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int b=nums[0];
        int sum=b;
        for(int i=1;i<nums.length;i++)
        {
            if(b<0)
                b=nums[i];
            else
                b+=nums[i];
            if(b>sum)
                sum=b;
        }
        return sum;
    }
}
```