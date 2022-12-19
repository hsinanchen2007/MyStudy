### 解题思路
摩尔投票法

### 代码

```php
class Solution {

    /**
     * 摩尔投票的算法
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $length = count($nums);
        $count = 1;
        $num = $nums[0];
        for ($i=1; $i<$length; $i++) {

            if ($count == 0) {
                $num = $nums[$i];
                $count = 1;
            } else {
                if ($num == $nums[$i]) {
                    $count ++;
                } else {
                    $count --;
                }
            }
        }

        return $num;
    }
}
```