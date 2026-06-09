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
         if (count($nums)<=1) return $nums;
        $middle = $nums[0];
        $left = [];
        $right = [];

        for ($j = 1;$j<count($nums);$j++){
            if ($middle >$nums[$j]){
                $left[] = $nums[$j];
            }else{
                $right[] = $nums[$j];
            }
        }

        $left = self::sortArray($left);
        $right = self::sortArray($right);

        return  array_merge($left,[$middle],$right);
    }
}
```