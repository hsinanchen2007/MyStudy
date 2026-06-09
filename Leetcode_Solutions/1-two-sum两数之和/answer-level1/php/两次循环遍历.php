### 解题思路
1.将数组中的健值反转
2.目标值-输入值=a 的结果也一定在给出的数组中，判断a是否在第一步反转后的数组中存在，如果存在就能找到对应的结果
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {

        $newArr = array_flip($nums);
        $len = count($nums);
        for($i = 0; $i < $len; $i++) {
            $other = $target - $nums[$i];
            if (isset($newArr[$other]) && $i != $newArr[$other]) {

                return [$i, $newArr[$other]];
            }
        }
    }
}
```