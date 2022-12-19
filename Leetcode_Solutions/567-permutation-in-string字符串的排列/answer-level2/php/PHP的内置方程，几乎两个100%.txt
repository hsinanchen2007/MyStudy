### 解题思路
PHP内建的count_chars($string, $mode)有计算字串中每个字符出现次数并弹回结果的功能，直接使用就结束了

根据不同的 mode，count_chars() 返回下列不同的结果：

0 - 以所有的每个字节值作为键名，出现次数作为值的数组。
1 - 与 0 相同，但只列出出现次数大于零的字节值。
2 - 与 0 相同，但只列出出现次数等于零的字节值。
3 - 返回由所有使用了的字节值组成的字符串。
4 - 返回由所有未使用的字节值组成的字符串。


### 代码

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function checkInclusion($s1, $s2) {
        $size1 = strlen($s1);
        $size2 = strlen($s2);
        
        if($size1 > $size2) return false;

        $s1_array = count_chars($s1,1);//返回s1每个字符出现次数的数组，index为该字符的ascii值
        
        //循环至长字串减去短字串的位置即可
        $start = 0;//从长字串中截取子字串的开始位置
        while($start <= $size2-$size1){
            $sub_str = substr($s2, $start, $size1);//长字串中的子字串
            $substr_array = count_chars($sub_str,1);
            if($s1_array == $substr_array) return true;
            $start++;
        }
        
        return false;
    }
}
```