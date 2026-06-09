### 解题思路
两个坐标依次位移

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function triangleNumber($nums) {
        $cnt = count($nums);
        sort($nums);
        $ret = 0;
        for($i = 0; $i < $cnt-2; $i ++){
            $j = $i+1;
            $k = $i+2;
            while($j < $k && $k < $cnt){
                //echo json_encode([$nums[$i],$nums[$j],$nums[$k],$ret]);echo "\n";
                if($nums[$i] + $nums[$j] <= $nums[$k]){
                    $ret += ($k - $j - 1);
                    if($k == $cnt - 1){
                        $j++;
                    }else if($k - $j > 1){
                        $j++;
                    }else{
                        $j++;
                        $k++;
                    }
                }else if($k > $j && $k == $cnt -1){
                    $ret += ($k - $j);
                    $j++;
                }else{
                    if($k == $cnt - 1){
                        $j++;
                    }else{
                        $k++;
                    }
                }
            }
        }
        return $ret;
    }
}
```