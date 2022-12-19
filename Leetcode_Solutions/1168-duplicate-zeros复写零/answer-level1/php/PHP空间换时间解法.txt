因为是原地处理数据,空间复杂度为O(1),最坏时间复杂度O(n),最好时间复杂度O(1)
```
class Solution {

    /**
     * @param Integer[] $arr
     * @return NULL
     */
    function duplicateZeros(&$arr) {
        $count = count($arr);
        for ($i = 0;$i < $count; $i++) {
            if ($arr[$i] == 0 && $i != $count - 1) {
                for ($j=$count-1;$j>$i+1;$j--) {
                    $arr[$j] = $arr[$j-1];
                }
                $arr[$i+1] = 0;
                $i++;
            }
        }
    }
}
```
