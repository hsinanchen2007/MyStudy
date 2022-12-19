### 解题思路
无需太多解释

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findLengthOfLCIS($nums) {
        $size = count($nums);
        
        if($size==0) return 0;

        $max_len = 1;
        $cur_len = 1;
        $start = 0;
        
        while($start < $size-1){
            if($nums[$start] < $nums[$start+1]) {
                $cur_len++;
                $max_len = max($max_len, $cur_len);
            }
            else{
                $cur_len = 1;
            }
            $start++;
        }


        return $max_len;
    }
}
```