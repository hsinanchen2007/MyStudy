之前看过一道二维数组旋转的题,与这道题类似.
只要在纸上画一画,找好映射关系,很容易想明白
```
class Solution {

    /**
     * @param Integer[][] $A
     * @return Integer[][]
     */
    function transpose($A) {
        $count1 = count($A);
        $count2 = count($A[0]);
        $out = [];
        for ($i=0;$i<$count1;$i++) {
            for($j=0;$j<$count2;$j++){
                $out[$j][$i] = $A[$i][$j];
            }
        }
        return $out;
    }
}
```
