### 解题思路
哈希记数

### 性能
执行用时 :44 ms, 在所有 php 提交中击败了61.54%的用户
内存消耗 :15.3 MB, 在所有 php 提交中击败了33.33%的用户

效率比预计的低，需要优化

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        $map = [];
        for ($i = 0; $i < strlen($s); $i++) {
            $map[$s[$i]] += 1;
        }

        for ($i = 0; $i < strlen($s); $i++) {
            if ($map[$s[$i]] == 1) {
                return $i;
            }
        }

        return -1;
    }
}
```