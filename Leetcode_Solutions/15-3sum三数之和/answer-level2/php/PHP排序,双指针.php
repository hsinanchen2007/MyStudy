向大佬学习,敲完受益颇丰,给出PHP实现方法
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        sort($nums);
        $tem = [];
        $count = count($nums);

        for ($i=0; $i < $count - 2; $i++) {
            if ($i > 0 && $nums[$i-1] == $nums[$i]) {
                continue;
            }
            $l = $i + 1;
            $r = $count - 1;
            while ($l < $r) {
                if ($nums[$r] > -$nums[$i] - $nums[$l]) {
                    while ($l < $r && $nums[$r - 1] == $nums[$r]) {
                        $r--;
                    }
                    $r--;
                } elseif ($nums[$r] < -$nums[$i]-$nums[$l]) {
                    while ($l < $r && $nums[$l + 1] == $nums[$l]) {
                        $l++;
                    }
                    $l++;
                } else {
                    $tem[] = [$nums[$i], $nums[$l], $nums[$r]];
                    while ($l < $r && $nums[$r-1] == $nums[$r]) {
                        $r--;
                    }
                    while ($l < $r && $nums[$l+1] == $nums[$l]) {
                        $l++;
                    }
                    $r--;
                    $l++;
                }
            }
        }
        return $tem;
    }
}
```
