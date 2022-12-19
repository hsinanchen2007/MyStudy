
## 题目描述
给你一个整数数组 `arr` 和一个整数 `difference`，请你找出 `arr` 中所有相邻元素之间的差等于给定 `difference` 的等差子序列，并返回其中最长的等差子序列的长度。

## 样例
示例 1：

>输入：`arr = [1,2,3,4], difference = 1`
输出：`4`
解释：最长的等差子序列是 `[1,2,3,4]`。

示例 2：

>输入：`arr = [1,3,5,7], difference = 1`
输出：`1`
解释：最长的等差子序列是任意单个元素。

示例 3：

>输入：`arr = [1,5,7,8,5,3,4,2,1], difference = -2`
输出：`4`
解释：最长的等差子序列是 `[7,5,3,1]`

## 思路
这道题思路比较简单，跟经典问题`最长递增（减）子序列`有点相似，而这道题称为`最长等差子序列`, 也就是说是固定公差的递增（减），相对还更简单一点。

可以用`dp[i]`来记录以数字`i`为结尾的`最长等差子序列`的长度，那么它应该只有两种情况：
- `dp[i] = 1  // 表示在 i 之前没有出现等差子序列`
- `dp[i] = dp[i - difference] + 1  // 表示在 i 之前出现了等差子序列，长度为 dp[i - difference], 而 i 也是满足这个等差序列的，所以等差序列的长度在此基础上加 1 就可以了`

考虑元素值会出现负数，所以用数组存放是不行的，那么可以用一个 `map`来维护以 `i` 结尾的最长等差序列的长度，所以也就不难得出如下代码：

`PS: ` 经评论提醒，可以为下标加一个偏置，解决出现负值的情况，这是很`OK`，因为这道题`arr[i]`、`difference`的数据范围已经给的很明确了，而且比较小。

## 代码

```java
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        int ans = 1;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i: arr) {
            int temp = map.getOrDefault(i - difference, 0) + 1;
            map.put(i, temp);
            ans = Math.max(ans, temp);
        }
        return ans;
    }
}
```

## 执行结果
![image.png](https://pic.leetcode-cn.com/ec81c6b1690c09d0aa8b0a3aeccec31e65c7d5a1d98813feac38ceb1f9fd732b-image.png)

