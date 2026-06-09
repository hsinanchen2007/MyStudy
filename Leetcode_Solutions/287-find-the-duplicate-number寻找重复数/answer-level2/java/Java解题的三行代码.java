时间复杂度O(n)，空间复杂度O(1)；
遍历数组，将数组值n的绝对值看作索引，将对应下标的值nums[n]乘上`-1`，如果遍历到一个负数，说明之前已经出现过同样的索引，因此n的绝对值就是重复数
```
class Solution {
    public int findDuplicate(int[] nums) {
        for(int n:nums){
            if(nums[Math.abs(n)-1]<0) return Math.abs(n);
            nums[Math.abs(n)-1] *= -1;
        }
        return -1;
    }
}
```
最后的return其实没起到作用，就勉强称作三行代码吧