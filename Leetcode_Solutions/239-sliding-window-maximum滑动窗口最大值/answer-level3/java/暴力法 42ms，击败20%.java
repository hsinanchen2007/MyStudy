### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0) {
            return nums;
            //return new int[]{}; //两种写法都行
        }
        int[] res = new int[nums.length- k + 1];
        for( int i = 0; i < nums.length - k+1; i++){
            int max = Integer.MIN_VALUE;
            for(int j = 0; j < k ; j++) {
                max = Math.max(max, nums[i + j]);
            }
            res[i] = max;
        }
        return res;
    }
}
```