### 解题思路
字符串转数组统计每个字母出现次数，判断两个数组是否相等

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isAnagram($s, $t) {
       $ss = array_count_values(str_split($s));
        $tt = array_count_values(str_split($t));
        if (count($ss)!=count($tt)) {
            return false;
        }
        if ($ss == $tt) {
            return true;
        }else{
            return false;
        }
    }
}
```