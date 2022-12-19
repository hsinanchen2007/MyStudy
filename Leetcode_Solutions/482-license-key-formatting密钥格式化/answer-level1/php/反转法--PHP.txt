### 解题思路
反转字符串，根据K来分组即可。

### 性能
执行用时 :120 ms, 在所有 PHP 提交中击败了10.00%的用户
内存消耗 :15.4 MB, 在所有 PHP 提交中击败了80.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @param Integer $K
     * @return String
     */
    function licenseKeyFormatting($S, $K) {
        $res = '';
        $S = strrev(strtoupper(str_replace('-', '', $S)));
        for ($i = 0; $i < strlen($S); $i++) {
            if ($i % $K == 0 && $i != 0) {
                $res = '-' . $res;
            }
            $res = $S[$i] . $res;
        }

        return $res;
    }
}
```

### 参考
[逆序](https://leetcode-cn.com/problems/license-key-formatting/solution/ni-xu-jian-ji-dai-ma-by-niu-meng/)