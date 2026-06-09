### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        return ($a = intval(trim(str_replace("e","#",$str)))) > 2147483647 ? 2147483647 : ($a < -2147483648 ? -2147483648 : $a);
    }
}
```