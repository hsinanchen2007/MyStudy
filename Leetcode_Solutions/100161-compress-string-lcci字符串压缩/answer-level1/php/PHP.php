### 解题思路
此处撰写解题思路
本题的解题思路比较清晰，一遍便来字符串S即可，在遍历时做统计，声明变量candidata作为当前的选举者，然后判断当前字符串是否与选举者相同，若是则累加；若不是，则进行字符串的拼接。
在使用php处理的时候，在判断不相等时，有一个小技巧，即多处理一位，判断字符串终止条件，完成最后一个字符串统计结果的拼接工作。
### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function compressString($S) {
        $len = strlen($S);
        $candidate = '';
        $str = '';
        $count = 0;
        for ($i = 0; $i <= $len; $i ++) {
            if ($S[$i] != $candidate) {
                if ($candidate) {
                    $str .= $candidate . ((string)$count);
                }
                $candidate = $S[$i];
                $count = 0;
            }
            $count ++;
        }
        return strlen($str) >= $len ? $S : $str;
    }
}
```