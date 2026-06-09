class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function fib($N) {
        if($N < 1){
            return 0;
        }elseif($N == 1 || $N == 2){
            return 1;
        }
        return $this->fib($N-1) + $this->fib($N-2);
    }
}