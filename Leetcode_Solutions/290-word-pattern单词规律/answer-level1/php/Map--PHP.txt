### 解题思路
使用哈希

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了47.06%的用户
内存消耗 :14.7 MB, 在所有 php 提交中击败了41.67%的用户

### 代码

```php
class Solution {

    /**
     * @param String $pattern
     * @param String $str
     * @return Boolean
     */
    function wordPattern($pattern, $str) {
        $arr = explode(' ', $str);
        if (strlen($pattern) != count($arr)) {
            return false;
        }

        $mapp = $maps = [];
        for ($i = 0; $i < strlen($pattern); $i++) {
            $mapp[$pattern[$i]] = $arr[$i];
            $maps[$arr[$i]] = $pattern[$i];
        }

        for ($i = 0; $i < strlen($pattern); $i++) {
            if ($mapp[$pattern[$i]] != $arr[$i] OR $maps[$arr[$i]] != $pattern[$i]) {
                return false;
            }
        }

        return true;
    }
}
```