时间复杂度O(n),一奇一偶然后合并
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParity($A) {
        $count = count($A);
        $ou = $ji = [];
        for ($i=0;$i<$count;$i++) {
            if ($A[$i] % 2 == 0) {
                $ou[] = $A[$i];
            } else {
                $ji[] = $A[$i];
            }
        }
        return array_merge($ou,$ji);
    }
}
```
