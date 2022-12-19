### 解题思路
根据官方算法公式解。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($A) {
        sort($A);
        $ans=$taken=0;
        $count = count($A);
        for($i=1; $i<$count; ++$i){
            if($A[$i-1] == $A[$i]) {
                $taken++;
                $ans -= $A[$i];
            } else {
                $give = min($taken, $A[$i]-$A[$i-1]-1);
                $ans += $give * ($give+1)/2 + $give*$A[$i-1];
                $taken -= $give;
            }
        }
        if($count>0)
        $ans += $taken*($taken+1)/2 + $taken*$A[$count-1];
        return $ans;
    }
}
```