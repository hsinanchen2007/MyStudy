class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        if($n==0){
            return 0;
        }
        if($n==1){
            return 1;
        }
        $pre=0;
        $cur=1;
        for($i=2;$i<=$n;$i++){
            $temp=($pre+$cur)%1000000007;
            $pre=$cur;
            $cur=$temp;

        }
        return $cur;

    }
}