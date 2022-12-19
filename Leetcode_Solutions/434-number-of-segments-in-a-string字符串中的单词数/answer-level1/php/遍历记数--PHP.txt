### 解题思路
遍历，如果不是空格就记数

### 注意
$count需要初始化，不然返回值类型不一致。PHPer要注意啊。

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了30.00%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了12.50%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function countSegments($s) {
        $count = 0;
        for ($i = 0; $i < strlen($s); $i++) {
            if (($i == 0 OR $s[$i - 1] == ' ') && $s[$i] != ' ') {
                $count++;
            }
        }

        return $count;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/number-of-segments-in-a-string/solution/zi-fu-chuan-zhong-de-dan-ci-shu-by-leetcode/](https://leetcode-cn.com/problems/number-of-segments-in-a-string/solution/zi-fu-chuan-zhong-de-dan-ci-shu-by-leetcode/)