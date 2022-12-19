
[题目传送门](https://leetcode-cn.com/problems/queens-that-can-attack-the-king/)

我直接把8种情况列出来了...
国王的坐标为(i, j), 白皇后的坐标为(qi, qj)
1. 同一行 i = qi: 找最靠近的两列
2. 同一列 j = qj: 找最近的两行
3. 对角线1: i + j = qi + qj
4. 对角线2: i - j = qi - qj


``` php
class Solution {

    /**
     * @param Integer[][] $queens
     * @param Integer[] $king
     * @return Integer[][]
     */
    function queensAttacktheKing($queens, $king) {
        $r = [];
        $i = $king[0];
        $j = $king[1];
        for($m = 0; $m < count($queens); $m++) {
            $item = $queens[$m];
            $qi = $item[0];
            $qj = $item[1];
            if($qi === $i && $qj < $j) {
                if(!isset($r[0]) || (isset($r[0]) && $r[0][1] < $qj)) {
                    $r[0] = $item;
                }
                continue;
            }
            if($qi === $i && $qj > $j) {
                if(!isset($r[1]) || (isset($r[1]) && $r[1][1] > $qj)) {
                    $r[1] = $item;
                }
                continue;
            }
            if($qj === $j && $qi < $i) {
                if(!isset($r[2]) || (isset($r[2]) && $r[2][0] < $qi)) {
                    $r[2] = $item;
                }
                continue;
            }
            if($qj === $j && $qi > $i) {
                if(!isset($r[3]) || (isset($r[3]) && $r[3][0] > $qi)) {
                    $r[3] = $item;
                }
                continue;
            }
            if($qi + $qj === $i + $j && $qj > $j) {
                if(!isset($r[4]) || (isset($r[4]) && $r[4][1] > $qj)) {
                    $r[4] = $item;
                }
                continue;
            }
            if($qi + $qj === $i + $j && $qj < $j) {
                if(!isset($r[5]) || (isset($r[5]) && $r[5][1] < $qj)) {
                    $r[5] = $item;
                }
                continue;
            }
            if($qj - $qi === $j - $i && $qi > $i) {
                if(!isset($r[6]) || (isset($r[6]) && $r[6][0] > $qi)) {
                    $r[6] = $item;
                }
                continue;
            }
            if($qj - $qi === $j - $i && $qi < $i) {
                if(!isset($r[7]) || (isset($r[7]) && $r[7][0] < $qi)) {
                    $r[7] = $item;
                }
                continue;
            }
        }
        return array_values($r);
    }
}
```
