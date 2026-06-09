很巧妙的解法
1. 翻转整个数组
2. 翻转数组前 k 个元素
3. 翻转数组后面的部分

> k > count(nums), 需提前处理

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return NULL
     */
    function rotate(&$nums, $k)
    {
        $len = count($nums);
        if ($k > $len) {
            $k = $k % $len;
        }
        $nums = $this->reverse($nums, 0, $len - 1);
        $nums = $this->reverse($nums, 0, $k - 1);
        $nums = $this->reverse($nums, $k, $len - 1);
        return $nums;
    }

    private function reverse($arr, $left, $right)
    {
        while ($left <= $right) {
            $tmp = $arr[$left];
            $arr[$left] = $arr[$right];
            $arr[$right] = $tmp;
            $left++;
            $right--;
        }

        return $arr;
    }
}
```
