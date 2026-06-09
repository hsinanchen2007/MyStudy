将数组顺序排好,与现有数组每一个值作对比,不同则代表站队错误
```
class Solution {

    /**
     * @param Integer[] $heights
     * @return Integer
     */
    function heightChecker($heights) {
        if (empty($heights)) {
            return 0;
        }
        $out = 0;
        $arr = $heights;
        asort($heights);
        $times = 0;
        foreach ($heights as $value) {
            if ($value != $arr[$times]) {
                $out++;
            }
            $times++;
        }
        return $out;
    }
}
```
