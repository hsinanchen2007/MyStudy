### 解题思路
桶排序+鸽巢原理
自己没写出来，参考 liweiwei1419的思路写的。

**难点在于如果出现1233重复的数据，交替会出现死循环**

```
1. $nums[$i] != $i+1 && $nums[$i-1] != $nums[$i]
2. // 简化之后
2. $nums[$nums[$i] - 1] != $nums[$i]

```

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
      
        $count = count($nums);
        for ($i = 0; $i < $count; $i++) {

            // 如果只交换一次，肯定还有数据不符合应该出现的位置，需要不停的交换，直到交换结束
            // 交换数据满足需要满足
            // 1.要交换的数据必须大于0，2.要交换的数据必须等于小于$count,
            // 3.要交换的数据必须不在应该出现的位置（$nums[2] != 3即 $nums[$i]!=$i+1）
            // 为了避免死循环，如 122 这种情况，增加一个条件i-1的值不能等于 i 的值
            // $nums[$i] != $i+1 && $nums[$i-1] != $nums[$i]
            // 简化一下就是当前的值-1=前一个值的 key即 前一个值不能与当前值才做数据交换 $nums[$nums[$i] - 1] != $nums[$i]
            while ($nums[$i] > 0 && $nums[$i] <= $count && $nums[$nums[$i] - 1] != $nums[$i]) {
                echo sprintf("nums[1]=%s, i=%s\n", $nums[$i], $i);
                $swapIndex = $nums[$i] - 1;
                $swapValue = $nums[$swapIndex];

                $nums[$swapIndex] = $nums[$i];
                $nums[$i] = $swapValue;
            }
        }

        // 循环数组，发现异常的那个值=i+1
        for ($i = 0; $i <= $count; $i++) {
            if ($nums[$i] != $i + 1) return $i + 1;
        }

    }
}
```