说明：求z是否是x与y的最小公倍数的倍数
```
class Solution {

    /**
     * @param Integer $x
     * @param Integer $y
     * @param Integer $z
     * @return Boolean
     */
    function canMeasureWater($x, $y, $z) {
        if($x+$y<$z) return false;
        $gcd = $this->gcd($x,$y);
        return $gcd==0 ? true : (fmod($z,$gcd)==0 ? true : false);
    }
    
    function gcd($n,$m){
        if(!$m) return $n;
        return $this->gcd($m,fmod($n,$m));
    }
}
```
