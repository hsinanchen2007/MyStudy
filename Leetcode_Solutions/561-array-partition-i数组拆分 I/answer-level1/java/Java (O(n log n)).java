### 解题思路
只需要确保每一对的差值最小，即可得到总和最大。所以先花O(n logn)排序一遍，然后再取每一对左边即可。

### 代码

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length; i = i + 2){
            sum += nums[i];
        }
        return sum;
    }
}
```