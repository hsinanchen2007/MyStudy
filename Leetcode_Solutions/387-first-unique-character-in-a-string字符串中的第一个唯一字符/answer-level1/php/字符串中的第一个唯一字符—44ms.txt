### 解题思路
将字符串分割成数组，并统计出现次数，返回第一个统计数为1的位置

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        if ($s== null) {
            return '-1';
        }
        $st = str_split($s);
        $arr = array_count_values($st);
        for ($i = 0; $i < count($st); $i++) {
            if ($arr[$st[$i]]==1) {
                return $i;
            }
        }
        return '-1';
    }
}
```