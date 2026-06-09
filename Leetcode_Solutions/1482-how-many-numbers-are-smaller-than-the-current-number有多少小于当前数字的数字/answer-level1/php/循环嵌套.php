### 解题思路


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function smallerNumbersThanCurrent($nums) {
        $new_array = [];
        foreach($nums as $k=>$v){
            $value = 0;
            foreach($nums as $kk=>$vv){
                if($k != $kk && $v>$vv){
                    $value += 1;
                }
            }
            $new_array[] = $value;
        }
        return $new_array;
    }
}
```