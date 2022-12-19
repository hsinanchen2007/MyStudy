![5HTN7AMWTYLE\[_NL4(OBVRG.png](https://pic.leetcode-cn.com/880186de91bc26759132b3309ac61903451c47c298c3656a01098f634e5895ce-5HTN7AMWTYLE%5B_NL4\(OBVRG.png)
```
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return Boolean
     */
    function isToeplitzMatrix($matrix) {
        $c1 = count($matrix);
        $c2 = count($matrix[0]);
        for($j=1;$j<$c1;$j++){
            $m2 = $matrix;
            array_shift($m2[$j]);
            array_pop($m2[$j-1]);
            if($m2[$j] != $m2[$j-1])  return false;
        }
        return ture;
    }
}
```
