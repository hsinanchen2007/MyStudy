### 解题思路
判断字符出现的次数，出现和重复一次计数加一，如果后面字符不一样或是最后一个字符，则拼接字符

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n) {
        if ($n == 1) return '1';
        $str = '1';
        $count = 0;
        while ($n - 1) {
            $newstr = '';
            for ($i = 0; $i < strlen($str); $i++) {
                if ($i == strlen($str) - 1) {
                    // 判断是不是最后一个数，是的话直接拼接数组
                    $count++;
                    $newstr .= $count . $str[$i];
                    $count = 0;
                } else if ($str[$i] == $str[$i + 1]) {
                    // 如果下个字符重复，则计数加一
                    $count++;
                } else {
                    // 如果下个字符不重复，则计数加一后拼接数组，比如21中，先产生12
                    $count++;
                    $newstr .= $count . $str[$i];
                    $count = 0;
                }
            }
            $str = $newstr;
            $n--;
        }
        return $str;
        
    }
}
```