```
class Solution {

    /**
     * @param Integer[] $cost
     * @return Integer
     */
    function minCostClimbingStairs($cost) {
        $count = count($cost);
        $a = $cost[0]; // 存储第一步
        $b = $cost[1]; // 存储第二步
        for ($i=2;$i<$count;$i++) {
            $tmp = $a > $b ? $b : $a; // 判断最小的体力
            $tmp += $cost[$i]; // 加上下一步的体力
            # 存储体力
            $a = $b;
            $b = $tmp;
        }
        # 拿到少体力
        return min($a, $b);
    }
}
```
