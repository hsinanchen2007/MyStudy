### 解题思路
要找出结果的最大值，就尽可能地将大数留出来，如果一个最大的数a和一个最小的数b一组，那么min(a,b)=b,这样较大数就被筛选掉了，为了尽可能地保留大数，因此应该使每一组min(x,y)中的x与y差值最小，将数组进行排序后相邻两个数的差值就最小。直接将偶数位的元素相加就是结果的最大值。
### 代码

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        int sum = 0;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i+=2){
            sum += nums[i];
        }
        return sum;
    }
}
```