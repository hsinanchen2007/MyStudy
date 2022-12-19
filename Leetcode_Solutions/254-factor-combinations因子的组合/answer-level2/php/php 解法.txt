递归
```
class Solution {

    /**
     * @param Integer $n
     * @return Integer[][]
     */
    function getFactors($n) {
        $ans = [];
        $this->helper($n, 2, [], $ans);
        return $ans;
    }

    function helper($n, $start, $list, &$ans){
        $sqrt = floor(sqrt($n));
        for($i=$start; $i<=$sqrt; $i++){
            if($n % $i == 0){
                $list[] = $i;
                $list[] = $n/$i;
                $ans[] = $list;
                array_pop($list);
                $this->helper($n/$i,$i, $list, $ans);
                array_pop($list);
            }
        }
    }
}
```
