```
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    //Time:O(2^n),Space(n)
    function fib($N) {
        if ($N <= 1) return $N;
        return $this->fib($N - 1) + $this->fib($N - 2);
    }

    //Time:O(n),Space(n)
    function fibIterative($N) {
        if ($N <= 1) return $N;

        $d[0] = 0;
        $d[1] = 1;
        for ($i = 2; $i <= $N; ++$i) {
            $d[$i] = $d[$i-1] + $d[$i-2];
        }
        return $d[$N];
    }

    //Time:O(n),Space(1)
    function fibIterativeO1($N) {
        if ($N <= 1) return $N;

        $first = 0; $second = 1;
        for ($i = 2; $i <= $N; ++$i) {
            $third = $first + $second;
            $first = $second;
            $second = $third;
        }
        return $second;
    }
}
```
