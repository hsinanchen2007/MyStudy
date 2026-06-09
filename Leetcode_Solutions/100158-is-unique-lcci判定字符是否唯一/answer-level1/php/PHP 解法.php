### 解题思路

借助一个哈希表来判断

### 代码

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $len = strlen($astr);
        if ($len <= 1) {
            return true;
        }

        $hash = [];
        for ($i = 0; $i < $len; ++$i) {
            $char = substr($astr, $i, 1);
            if (isset($hash[$char])) {
                return false;
            }
            $hash[$char] = 1;
        } 

        return true;
    }
}
```