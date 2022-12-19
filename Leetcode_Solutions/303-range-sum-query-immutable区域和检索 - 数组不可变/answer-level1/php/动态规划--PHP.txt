### 解题思路
采用动态规划

算法：
0、第i个元素的状态定义为dp[i] 
1、约定dp[0] = 0，所以dp的长度比num多1
2、dp[i] = sum(num[0], num[i - 1])
即num第一个元素到第i个元素的和，应该是sum(num[0], num[i - 1])。
3、状态转移方程：
num[i - 1]实际是num第i个元素，是dp中第i + 1个元素
```
dp[i] = dp[i - 1] + num[i - 1]
dp[i][j] = dp[j + 1] - dp[i]
```

**注意：约定了dp[0]为0，所以dp[1]实际是num第一个元素, num第一个元素下标是0。dp[$j + 1]实际是num中0到j的和, 理解这个很重要。**

为什么是dp[j + 1] - dp[i], 不应该是dp[j] - dp[i]吗？
示例：
数组：  [-2, 1,  0,  4,  5]
下标：  [0,  1,  2,  3,  4]
dp数组：[0,  -2, -1, -1, 3, 8]
dp下标: [0,   1,  2,  3, 4, 5]

i和j是num中下标，例如[i, j] = [2, 3], sunrange(2, 3) = sum(num[3]) - sum(num[1]) = sum([-2, 1, 0, 4]) - sum([-2, 1]) = 3 - (-1) = 4


### 性能
执行用时 :36 ms, 在所有 php 提交中击败了88.89%的用户
内存消耗 :21.9 MB, 在所有 php 提交中击败了10.00%的用户

### 代码

```php
class NumArray {
    /**
     * @param Integer[] $nums
     */
    function __construct($nums) {
        $this->dp = [];
        $this->dp[0] = 0;
        for ($i = 1; $i <= count($nums); $i++) {
            $this->dp[$i] = $this->dp[$i - 1] + $nums[$i - 1];
        }
    }
  
    /**
     * @param Integer $i
     * @param Integer $j
     * @return Integer
     */
    function sumRange($i, $j) {
        return $this->dp[$j + 1] - $this->dp[$i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * $obj = NumArray($nums);
 * $ret_1 = $obj->sumRange($i, $j);
 */
```