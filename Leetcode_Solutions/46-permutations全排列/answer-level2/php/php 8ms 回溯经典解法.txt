### 解题思路
这是一道经典的回溯算法。
回溯中参数为原始数组nums，以及当前数组arr
回溯的终止条件为，当前arr的个数已经等于原始数组nums
回溯的处理，循环遍历原始数组nums,当前值不存在arr中时，将该值放入arr中，递归调用
由于上面的行为会找到最终答案，所以，在处理完上面请求时，将arr进行出栈操作，继续遍历

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permute($nums) {
        $this->backtracking($nums, []);
        return $this->res;
    }
    function backtracking($nums, $arr) {
            if (count($arr) == count($nums)) {
                $this->res[] = $arr;
                return;
            }

            foreach ($nums as $value) {
                if (!in_array($value, $arr)) {
                    $arr[] = $value;
                    $this->backtracking($nums, $arr);
                    array_pop($arr);
                }
            }
        }
}
```