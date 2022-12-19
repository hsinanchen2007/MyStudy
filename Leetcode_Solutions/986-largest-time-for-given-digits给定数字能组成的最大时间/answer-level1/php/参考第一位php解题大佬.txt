### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return String
     */
    function largestTimeFromDigits($A) {
      $return = '';
      for($i = 0;$i<4;$i++){
          for($j = 0;$j<4;$j++){
            if($j != $i){
                for($k = 0;$k<4;$k++){
                    if($k != $i && $k != $j){
                        $l = 6-$i-$j-$k;
                        if($A[$i]*10+$A[$j] <= 23 && $A[$k]*10+$A[$l] <=59){
                            $return = max($return,sprintf('%d%d:%d%d',$A[$i],$A[$j],$A[$k],$A[$l]));
                        }

                    }
                }
            }
          }
       }
       return $return;
    }
}
```