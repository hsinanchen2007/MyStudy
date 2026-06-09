### 解题思路
最大最小一般首先考虑排序，然后分以下集中情况。
1. 如果数组都是大于等于零的，这种好说，肯定是排序后最后面的三个最大的数的乘积
2. 如果有小于零的，那也要分情况 ：
a.是否有两个以上小于零的，如果有两个以上小于零的，负负得正，要取最大的 
b.如果只有一个小于零的，那还是最后三个最大的乘积。
可以画一画，很好理解。

### 代码

```java
class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] >= 0) {
            return nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3];
        } else {
            if (nums[1] < 0) {
                return Math.max(nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3], 
                        nums[0] * nums[1] * nums[nums.length - 1]);
            } else {
                return nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3];
            }
        }
    }
}
```