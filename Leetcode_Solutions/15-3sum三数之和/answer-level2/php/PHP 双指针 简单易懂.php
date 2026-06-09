### 解题思路
固定一个数$nums[$i] ; 剩下的就是twoSum问题

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        
        sort($nums);
        $length = count($nums);
        $hash = [];

       for($i=0;$i<$length;$i++){
        $l = $i + 1;
        $r = $length - 1;

        while($l < $r){
           
            if($nums[$i] + $nums[$l] + $nums[$r] == 0){
                $hash[$nums[$i] . $nums[$l] . $nums[$r]] = [$nums[$i] , $nums[$l] , $nums[$r]];
                $l++;
                $r--;
            }elseif($nums[$i] + $nums[$l] + $nums[$r] < 0){ // 小于0, 指针往右移
                $l++;
            }else{ //大于0 ， 指针往左移
                $r--;
            }
        }
    }
    return array_values($hash );
    }
}
```