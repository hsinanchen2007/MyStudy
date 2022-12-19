### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {

        if($target<$nums[0])
        {
            return 0;
        }
        $count = count($nums)-1;
        if($target>$nums[$count])
        {
           return ++$count;
        }
        foreach($nums as $key =>$val)
        {
                if($val>=$target)
                {
                    return $key;
                }
            
        }
    }
}
```