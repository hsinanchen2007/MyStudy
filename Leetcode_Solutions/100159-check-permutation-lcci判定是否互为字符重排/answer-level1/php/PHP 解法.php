### 解题思路

直接上代码

### 代码

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function CheckPermutation($s1, $s2) {
        if (strlen($s1) != strlen($s2)) return false;
        $arr1 = str_split($s1);
        $arr2 = str_split($s2);
        sort($arr1);
        sort($arr2);
        return $arr1 == $arr2;
    }
}
```