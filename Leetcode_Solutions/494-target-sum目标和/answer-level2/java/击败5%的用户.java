### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    // cnt变量记录方法数
    private int cnt;
    public int findTargetSumWays(int[] nums, int S) {
        // 如果数组长度为0，则答案肯定是零
        if(nums.length == 0){
            return 0;
        }
        // start从零开始
        findTargetSumWays(nums, 0, S);
        return cnt;
    }
    // 从nums数组的start出开始，找到和为S的子集
    private void findTargetSumWays(int[] nums, int start, int S){
        // 如果何为0，且start已经走到数组最后，则说明找到了一种方案
        if(S == 0 && start == nums.length){
            cnt++;
            return;
        }
        // 如果start走到了最后，但是S不为0,则说明不行
        if(start == nums.length){
            return;
        }
        // 数组start下标前面加负号
        findTargetSumWays(nums, start + 1, S - nums[start]);
        // 数组start下标前面加正号
        findTargetSumWays(nums, start + 1, S + nums[start]);
        return;

    }
}
```