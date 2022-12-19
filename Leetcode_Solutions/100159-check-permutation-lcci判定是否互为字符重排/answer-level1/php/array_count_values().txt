### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function CheckPermutation($s1, $s2) {
        return array_count_values(str_split($s1)) == array_count_values(str_split($s2));
    }
}
```