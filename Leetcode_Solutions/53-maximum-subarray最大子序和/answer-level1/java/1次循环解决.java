### 解题思路
1.考虑到最少有一个子元素,所以只需要判断只有一个子元素时,直接返回即可
2.声明两个变量,一个存储实时计算的最大值,一个先声明为int类型的最小值,每次计算时判断是否比存储的大,如果计算的为负则归0重新计算,循环一遍后即可得到最大子集的和

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 1) return nums[0];
        int count = 0;
        int max = -Integer.MIN_VALUE;
        for(int i = nums.length - 1;i >= 0;i--) {
            count += nums[i];
            if(count > max) max = count;
            if(count < 0) {
                count = nums[i] > 0 ? nums[i] : 0;
            }
        }
        return max;
    }
}
```