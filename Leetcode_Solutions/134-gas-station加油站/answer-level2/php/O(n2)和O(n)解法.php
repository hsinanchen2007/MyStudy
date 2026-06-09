### 解题思路
自己最开始写的是一次循环，另外一个指针一直前移，看了解析才知道还有更优解法。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $gas
     * @param Integer[] $cost
     * @return Integer
     */
    function canCompleteCircuit($gas, $cost) {
        if(array_sum($gas) < array_sum($cost)){
        return -1;
        }
        $n = count($gas);
        $curTotal = 0;
        $beginId = 0;
        for ($i=0; $i < $n; $i++) { 
            $curTotal += ($gas[$i] - $cost[$i]);
            if($curTotal < 0){
                $curTotal = 0;
                $beginId = $i + 1;
                continue;
            }
        }
        return $curTotal >= 0 ? $beginId : -1;
        /*$n = count($gas);
        for ($i=0; $i < $n; $i++) {
            $count = 0;
            $j = $i;
            $len = 0;
            while ($len < $n) {
                $count += $gas[$j];
                $count -= $cost[$j];
                $len++;
                $j++;
                if($j >= $n){
                    $j = 0;
                }
                if($count < 0){
                    break;
                }
            }
            if($count >= 0){
                return $i;
            }
        }
        return -1;*/
    }
}
```