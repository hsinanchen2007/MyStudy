如果你仔细思考过后,题的关键点是石子与石子之间只有一个空位,意味着只要移动一次即可.
例: .|.|. 移动最右面或者最左面'石子'到空位处即连续(|代表空位 .代表石子)
```
class Solution {

    /**
     * @param Integer $a
     * @param Integer $b
     * @param Integer $c
     * @return Integer[]
     */
    function numMovesStones($a, $b, $c) {
        $arr = [$a, $b, $c];
        sort($arr);
        $a = $arr[0];
        $b = $arr[1];
        $c = $arr[2];
        $atob = abs($a - $b);
        $ctob = abs($c - $b);
        if ($atob == 1 && $ctob == 1) {
            return [0,0];
        }

        if ($atob <= 2 || $ctob <= 2) {
            $left = 1;
        } else {
            $left = 2;
        }

        $hatob = $atob > 1 ? $atob - 1 : 0;
        $hctob = $ctob > 1 ? $ctob - 1 : 0;

        return [$left,$hatob + $hctob];
    }
}
```
