### 解题思路
使用array_pop 或 unset

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function minSubsequence($nums) {
        sort($nums);
        $arr = [];
        foreach($nums as $v)
        {
            $arr[] = array_pop($nums);
            if (array_sum($arr) > array_sum($nums))
            {
                return $arr;
            }
        }
    }
}
```
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function minSubsequence($nums) {
        rsort($nums);
        $arr = [];
        foreach($nums as $k => $v)
        {
            unset($nums[$k]);
            $arr[] = $v;
            if (array_sum($arr) > array_sum($nums))
            {
                return $arr;
            }
        }
    }
}
```