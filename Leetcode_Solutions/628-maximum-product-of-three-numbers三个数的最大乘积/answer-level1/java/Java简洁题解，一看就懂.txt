### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximumProduct(int[] nums) {
        int n=nums.length;
        if(n==1 ||n==1||n==2) return 0;
        if(n==3) return nums[0]*nums[1]*nums[2];
        Arrays.sort(nums);
        //全为正数或者负数时时，最大值是nums[n-1]*nums[n-2]*nums[n-3]
        //其他情况下为最小的两个负数乘以最大的正数nums[n-1]*nums[0]*nums[1]
        return Math.max(nums[n-1]*nums[n-2]*nums[n-3],nums[n-1]*nums[0]*nums[1]);
    }
}
```