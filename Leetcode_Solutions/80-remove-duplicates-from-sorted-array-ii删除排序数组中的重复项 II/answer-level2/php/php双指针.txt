### 解题思路
php双指针
$i遍历原数组
$j储存有效数组

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $c = count($nums);
        if($c < 3){
            return $c;
        }
        $i = 2;
        $j = 2;
        while($i < $c){
            if($nums[$j-2] != $nums[$i]){
                 $nums[$j] = $nums[$i];
                 $j++;
            }
            $i++;
        }
        return $j;
    }
}
```