### 解题思路
1. 直接暴力

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function sumFourDivisors($nums) {
            $arr = array();
    $sum  = 0;
    foreach ($nums as $key => $value) {
        $a = $value;
        $arr[$key] = array();
        $arr[$key][] = 1;
        $arr[$key][] = $a;
        for($i = 2; $i <= sqrt($a); $i++){
            if($a % $i == 0){
                $arr[$key][] = $i;
                                if(!in_array($a / $i, $arr[$key]))
                    $arr[$key][] = $a / $i;
            }
        }

        if(count($arr[$key]) == 4){
            $sum += array_sum($arr[$key]);
        }
    }

    return $sum;
    }
}
```