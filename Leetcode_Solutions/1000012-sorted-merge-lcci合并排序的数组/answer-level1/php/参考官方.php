```
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $m
     * @param Integer[] $B
     * @param Integer $n
     * @return NULL
     */
    function merge($A, $m, $B, $n) {
        array_splice($A,$m,$n,$B);
        sort($A);
        return $A;
    }
}

```

