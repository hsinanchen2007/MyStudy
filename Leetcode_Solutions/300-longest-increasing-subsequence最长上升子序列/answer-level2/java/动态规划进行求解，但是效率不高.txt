### 解题思路
使用动态规划进行求解。
新建一个数组int[] length = new int[n]，用于存放nums数组在第i个元素之前的最大长度。
1. 首先将length[0] = 1，而后从i = 1(i = 1 ... n - 1)开始计算
2. 先将length[i] = 1, curMax = 1，而后向前遍历(j = i - 1)：若nums[j] < nums[i],则curMax = Math.max(curMax, length[j] + 1)；若nums[j] == nums[i]，则curMax = Math.max(curMax, length[j])，剩下情况不进行处理。
3. 遍历结束后length[i] = curMax，而后再得到最大值max = Math.max(max, curMax);

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int[] length = new int[n];
        int max = 1;
        length[0] = 1;
        for(int i = 1; i < n; i ++){
            length[i] = 1;
            int j = i - 1;
            int curMax = 1;
            while(j >= 0){
                if(nums[j] < nums[i] && curMax < length[j] + 1) curMax = length[j] + 1;
                else if(nums[j] == nums[i] && curMax < length[j]) curMax = length[j];
                j --;
            }
            length[i] = curMax;
            max = Math.max(max, curMax);
        }
        return max;
    }
}
```