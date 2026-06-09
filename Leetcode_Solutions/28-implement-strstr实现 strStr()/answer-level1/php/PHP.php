### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        if((empty($haystack) && empty($needle)) || empty($needle)) return 0;
        $key = strpos($haystack,$needle);
       return $key === false ? -1 : $key;
    }
}
```