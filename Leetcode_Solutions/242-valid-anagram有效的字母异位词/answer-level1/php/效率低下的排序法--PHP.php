### 解题思路
对字符串排序，后比较，如果一致就是有效的字母异位词。

注意：PHP sort是对数组排序的，并且是引用

### 性能
执行用时 :56 ms, 在所有 php 提交中击败了28.00%的用户
内存消耗 :21.3 MB, 在所有 php 提交中击败了5.17%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isAnagram($s, $t) {
        $s_arr = str_split($s);
        $t_arr = str_split($t);
        sort($s_arr);
        sort($t_arr);
        return $s_arr == $t_arr;
    }
}
```