class Solution {

    /**
     * @param Integer $n
     * @return Integer f(n)=f(n-2)+f(n-1)  f1=1 f2=2
     */
    function numWays($n) {
        if($n==0){
            return 1;
        }
        if($n==1){
            return 1;
        }
         if($n==2){
            return 2;
        }
        $pre=1;
        $cur=2;
        for($i=3;$i<=$n;$i++){

            $temp=($pre+$cur)%1000000007;
            $pre=$cur;
            $cur=$temp;


        }
        return $cur;
    }
}

