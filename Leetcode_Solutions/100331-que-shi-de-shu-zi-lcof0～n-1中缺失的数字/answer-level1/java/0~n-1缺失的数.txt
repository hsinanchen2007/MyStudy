### 解题思路
双百，直接公式，然后遍历一遍数组，就直接得到缺失的那个数
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n+((n-1)*n)/2;
        for(int i=0;i<n;i++){
            sum-=nums[i];
        }
        return sum;
    }
}
```