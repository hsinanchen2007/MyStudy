快速幂递归算法
```
class Solution {

    /**
     * @param Float $x
     * @param Integer $n
     * @return Float
     */
    function myPow($x, $n) {
        $un = (float) $n;
        if($n<0){
            $x = 1/$x;
            $un = -$un;
        }
        return $this->x2($x,$un);
    }
    
    function x2($x,$n){
        if($n == 0) return 1.0;
        $half = $this->x2($x,floor($n/2));
        if(fmod($n,2)==0){
            return $half*$half;
        }else{
            return $half*$half*$x;
        }
    }
}
```
