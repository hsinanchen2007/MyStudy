### 解题思路
2重循环遍历，组成的数二进制中每个1表示亮灯，灯的数量等于给定值，就符号条件。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了8.33%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String[]
     */
    function readBinaryWatch($num) {
        $res = [];
        for ($i = 0; $i < 12; $i++) {
            for ($j = 0; $j < 60; $j++) {
                $hour = decbin($i);
                $minute = decbin($j);
                if ((substr_count($hour, '1') + substr_count($minute, '1')) == $num) {
                    $res[] = sprintf('%d:%02d', $i, $j);
                }
            }
        }

        return $res;
    }
}
```

### 参考
[简单易理解的Golang代码](https://leetcode-cn.com/problems/binary-watch/solution/jian-dan-yi-li-jie-de-golangdai-ma-by-a-bai-152/)