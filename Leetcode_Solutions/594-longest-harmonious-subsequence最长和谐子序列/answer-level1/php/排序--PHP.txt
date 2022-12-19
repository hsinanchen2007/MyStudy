### 解题思路
排序后，遍历数组，找到跟当前元素差值小于等于1的下标start(这里可以每次都用0开始找，实际没必要，所以在上一次的start基础上往后找))，如果差值等于1，用当前元素下标 - start + 1就是符合要求的子序列，存入计数器，往后遍历遇到更长的就替换计数器。

### 性能
执行用时 :160 ms, 在所有 PHP 提交中击败了33.33%的用户
内存消耗 :16.2 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findLHS($nums) {
        sort($nums);
        $start = 0;
        $count = 0;
        for ($i = 0; $i < count($nums); $i++) {
            while ($nums[$i] - $nums[$start] > 1) $start++;

            if ($nums[$i] - $nums[$start] == 1) {
                $count = max($count, $i - $start + 1);
            }
        }

        return $count;
    }
}
```

### 参考
[coding_freshman的评论](https://leetcode-cn.com/problems/longest-harmonious-subsequence/comments/95369)