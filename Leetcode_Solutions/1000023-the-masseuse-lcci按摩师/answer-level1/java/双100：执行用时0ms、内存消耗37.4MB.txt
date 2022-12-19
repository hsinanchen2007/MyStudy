执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户; 内存消耗 : 37.4 MB , 在所有 Java 提交中击败了 100.00% 的用户

本算法菜鸟发现动态规划不一定就要往0-1背包的思路去靠，只要后面的结果依赖于前面已经计算出来的结果就可以考虑动态规划。

result数组：
result[i](i >= 2)表示当数组nums第 i - 2 个下标之前所有顾客预约的总时间的最大值。
（1）result[0]、result[1]是为了方便计算result[2]的
（2）result[i](i >= 2)取以下两种情况的最大值
 1）当前预约时长 + 前两个的最大预约时长，即 nums[i - 2] + result[i - 2]
 2）前一个的最大预约时长 result[i - 1]

```
class Solution {
    public int massage(int[] nums) {

        int[] result = new int[nums.length + 2];
        
        //result数组每个元素都记录已经接过的预约的最大总时长, 从result下标为2开始计算

        for(int i = 2; i < result.length; i++) {
            result[i] = Math.max(result[i - 1], nums[i - 2] + result[i - 2]);
        }

        //result的最后一个元素就是本题目的答案
        return result[result.length - 1];

    }
}
```

