**解题思路**
字符串压缩其实就是用当前字符与下一个字符做比对，如果相等则继续向下比对，否则的话就以当前字符拼接上当前字符的长度
**代码实现**
```
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function compressString($S) {
        if(!$S) {
            return $S;
        }

        $string = '';
        $temp = '';
        $count = strlen($S);
        for($i=0;$i<$count;$i++) {
            $temp = $temp . $S[$i];
            if($S[$i] != $S[$i + 1]) {
                $string .= $S[$i] . strlen($temp);
                $temp = '';
            }
        }

        return strlen($string) >= $count ? $S : $string;
    }
}
```
**时间复杂度**
遍历一次$S得到结果所以复杂度为O(n)

