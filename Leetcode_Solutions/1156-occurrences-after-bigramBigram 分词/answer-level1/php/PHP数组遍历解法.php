遍历一次,对比当前单次和下一个单词,符合则拿i+2的值,不是则继续.需要注意下边界判断
```
class Solution {

    /**
     * @param String $text
     * @param String $first
     * @param String $second
     * @return String[]
     */
    function findOcurrences($text, $first, $second) {
        if (empty($text)) {
            return [];
        }
        $arr = explode(' ', $text);
        $count = count($arr);
        $out = [];
        for ($i=0;$i<$count;$i++) {
            if (empty($arr[$i])) {
                continue;
            }
            if ($i==$count - 1) {
                break;
            }
            if ($arr[$i] == $first && $arr[$i+1] == $second && isset($arr[$i+2])) {
                $out[] = $arr[$i+2];
            }
        }
        return $out;
    }
}
```
