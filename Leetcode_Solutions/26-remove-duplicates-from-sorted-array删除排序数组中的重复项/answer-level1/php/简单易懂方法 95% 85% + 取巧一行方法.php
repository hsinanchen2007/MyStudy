### 解题思路
从后往前删，不需要额外空间

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $counter = count($nums);
        if ($counter <= 1) {
            return $counter;
        }

        while($counter > 1){
            if($nums[$counter-1] == $nums[$counter-2]){
                unset($nums[$counter-1]);
            }
            $counter--;
        }

        return count($nums);
    }
}
```

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        //或者可以取巧用这个内建方程，一行：
        return count(array_unique($nums));
    }
}
```