使用hash table映射,标记好宝石,再做石头中筛选.时间复杂度O(m+n),空间复杂度O(1)
```
class Solution {

    /**
     * @param String $J
     * @param String $S
     * @return Integer
     */
    function numJewelsInStones($J, $S) {
        $countJ = strlen($J);
        if ($countJ==0) {
            return 0;
        }
        $out = 0;
        $countS = strlen($S);
        $hash = [];
        for ($i=0;$i<$countJ;$i++) {
            $hash[$J[$i]] = 1;
        }
        for ($i=0;$i<$countS;$i++) {
            if (isset($hash[$S[$i]])) {
                $out++;
            }
        }
        return $out;
    }
}
```
