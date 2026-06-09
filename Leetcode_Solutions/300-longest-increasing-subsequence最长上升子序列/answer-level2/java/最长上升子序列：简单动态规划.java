### 解题思路
定义一个相同长度的数组，该数组记录到达该位置时的最长上升序列，初始化为1，转移方程为：result[i] = Math.max(result[j] + 1,result[i]);

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int length = nums.length;
        int[] result = new int[length];
        int max = 0;
        for (int i = 0; i < length; i++) {
            result[i] = 1;
        }
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                   result[i] = Math.max(result[j] + 1,result[i]);
                }
            }
            if(max < result[i]) max = result[i];
        }
        return max;
    }
}
```