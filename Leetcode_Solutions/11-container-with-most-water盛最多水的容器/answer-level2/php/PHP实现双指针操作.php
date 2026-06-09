根据大佬思路使用PHP实现,很有启发,时间复杂度O(n),空间复杂度O(1)
```
class Solution {
    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $area = 0;
        $l = 0;
        $r = count($height) - 1;
        while ($l < $r) {
            $area = max($area, min($height[$l], $height[$r]) * ($r-$l));
            if ($height[$l] < $height[$r]) {
                $l++;
            } else {
                $r--;
            }
        }
        return $area;
    }
}
```