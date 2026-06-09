### 解题思路
懒就完事了= =
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isNumber($s) {
        return is_numeric(trim($s))?true:false;
    }
}
```