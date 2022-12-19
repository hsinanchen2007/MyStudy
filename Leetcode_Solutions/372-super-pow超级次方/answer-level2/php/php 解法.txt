公式：(a*b)%c = ((a%c)*(b%c))%c
假设计算5^34 = (5^10)^3 * (5^1)^4
```
class Solution {

    /**
     * @param Integer $a
     * @param Integer[] $b
     * @return Integer
     */
    function superPow($a, $b) {
        $a %= 1337;
        $res = 1;
        for($i=count($b)-1;$i>=0;$i--){
            $pow = $b[$i];
            $res = ($res * $this->qpow($a, $pow)) % 1337;
            $a = $this->qpow($a, 10) % 1337;
        }
        return $res;
    }
    
    function qpow($a,$n){
        $res = 1;
        while($n > 0){
            if($n % 2) $res = ($res*$a) % 1337;
            $a = ($a * $a) % 1337;
            $n = (int) $n/2;
        }
        return $res;
    }
}
```
