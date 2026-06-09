### 解题思路
此处撰写解题思路
这个题的意思从字符串末尾来遍历同时如果不等于空格便开始计数，当count>0且==空格时，说明最后一个字符串读取完毕，直接返回
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
        $len = strlen($s);
        $count = 0;
        for ($i = $len - 1; $i >=0; $i --) {
            if ($count > 0 && $s[$i] == ' ') {
                return $count;
            }
            if ($s[$i] != ' ') {
                $count ++;
            }
        }
        return $count;
    }
}
```