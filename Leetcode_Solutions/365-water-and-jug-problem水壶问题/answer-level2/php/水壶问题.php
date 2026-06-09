### 解题思路
如果z=a*x+b*y（a，b均整），x与y最大公约数为g，那么z一定是g的整数倍，即z%g=0！
a*x=a*n*g,b*y=b*m*g,如果z=（a*n+b*m）g，那z就是g的整数倍

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @param Integer $y
     * @param Integer $z
     * @return Boolean
     */
    function canMeasureWater($x, $y, $z) {
        if($x+$y<$z){
            return false;
        }
        $getfmod=$this->getfmod($x,$y);
        return $getfmod==0?true:(fmod($z,$getfmod)==0?true:false);
        
        
    }
    function getfmod($n,$m){
        if(!$m){
            return $n;
        }
        return $this->getfmod($m,fmod($n,$m));
    }
}
```