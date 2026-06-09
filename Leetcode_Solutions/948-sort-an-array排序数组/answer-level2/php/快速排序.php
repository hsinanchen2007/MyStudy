### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortArray($nums) {
        $count = count($nums);
        if($count < 2){
            return $nums;
        } else {
            $mid = $nums[0];
            $left = [];
            $right = [];
            foreach($nums as $k => $num){
                if($k == 0){
                    continue;
                }
                if($num <= $mid){
                    $left[] = $num;
                } else {
                    $right[] = $num;
                }
            }
        }
           return array_merge(self::sortArray($left), [$mid], self::sortArray($right));
    }

  
}

```