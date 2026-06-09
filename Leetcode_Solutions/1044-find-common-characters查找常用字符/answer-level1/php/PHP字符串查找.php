![image.png](https://pic.leetcode-cn.com/577d130416a11cd9732fbdb853b3dff051c8c7637a03e34a125c27337e7fd816-image.png)
可能是这道题PHP就我一个人解答吧?

时间复杂度O(n),空间复杂度O(1)
```
class Solution {

    /**
     * @param String[] $A
     * @return String[]
     */
    function commonChars($A) {
        if (empty($A)) {
            return [];
        }
        $count = count($A);
        $out = [];
        $str = $A[0];
        $strLen = strlen($str);
        for ($i=0;$i<$strLen;$i++){
            $num = 1;
            $value = $str[$i];
            for ($j=1;$j<$count;$j++) {
                if (strpos($A[$j], $value) !== false) {
                    $num++;
                    $index = strpos($A[$j], $value);
                    $A[$j] = substr($A[$j], 0, $index) . substr($A[$j], $index + 1, strlen($A[$j]));
                }
            }

            if ($num % $count == 0) {
                $out[] = $value;
            }
        }

        return $out;
    }
}
```
