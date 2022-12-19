```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $len = count($nums);
        if ($len <= 1) {
            return $len;
        }

        // 双指针，快慢指针
        // 慢指针及其之前的元素为所有不重复的元素，快指针一次遍历
        $slow = 0;
        for ($fast = 1; $fast < $len; ++$fast) {
            if ($nums[$fast] != $nums[$slow]) {
                $slow++;
                // 减少不必要的原地交换
                if ($slow != $fast) {
                    $nums[$slow] = $nums[$fast];
                }
            }
        }

        // 返回不重复数字个数
        return $slow + 1;
    }
}
```