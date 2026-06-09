### 解题思路
1. 使用一个哈希数组存储，然后遍历nums,看看nums中target减去nums中的值在不在哈希数组中，存在则返回，否则将值存在哈希数组中。
2. 因为数组是有序递增的，所以可以使用两个指针指向首位两端，计算和，如果和比target大，则高位指针递减，否则低位指针递增，直到和与target相等。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        // // 关联数组
        // $tmp = [];

        // for ($i = 0; $i < count($nums); $i++) {
        //     if (isset($tmp[$target - $nums[$i]])) {
        //         return [$target - $nums[$i], $nums[$i]];
        //     }

        //     $tmp[$nums[$i]] = 1;
        // }

        $low = 0;
        $high = count($nums) - 1;

        $result = [];
        while($low < $high) {
            if ($nums[$low] + $nums[$high] > $target) {
                $high--;
            } elseif ($nums[$low] + $nums[$high] < $target) {
                $low++;
            } else {
                $result = [$nums[$low], $nums[$high]];
                break;
            }
        }

        return $result;
    }
}
```