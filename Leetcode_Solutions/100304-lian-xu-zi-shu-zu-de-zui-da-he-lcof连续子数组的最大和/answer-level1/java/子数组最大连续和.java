### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int max = Integer.MIN_VALUE;

        for(int i = 0;i<nums.length;i++){
            sum+=nums[i];

            if(sum>max)
                max=sum;
            
            if(sum<0)
                sum=0;

            
        }

        return max;
    }
}
```