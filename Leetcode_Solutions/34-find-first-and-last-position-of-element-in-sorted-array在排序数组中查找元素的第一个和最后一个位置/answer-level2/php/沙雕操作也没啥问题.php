# 题目分析

**初始位置的值是很好找的，关键点在于第二个位置，因为数组是有序的，如果存在初始位置并且下一个位置不等于给定值的话，那么返回的两个索引是一样的，即初始位置就是最后的位置，否则的话(这里我没有想到别的)，那么就进行再一次二分查找，也不知道这是机智还是沙雕哈哈哈。😃结果完全是可行的。**

**代码实现**
```
  * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function searchRange($nums, $target)
    {
        $data = [-1, -1];

        if (count($nums) == 0) {
            return $data;
        }
        $left  = 0;
        $right = count($nums) - 1;

        while ($left < $right) {
            $middle = ($left + $right) >> 1;
            if ($nums[$middle] < $target) {
                $left = $middle + 1;
            } else {
                $right = $middle;
            }
        }

        if ($nums[$left] == $target) {
            $data[0] = $left;
            if ($nums[++$left] != $target) {
                $data[1] = $data[0];
            } else {
                $r = count($nums) - 1;
                $l = $left;
                while ($l < $r) {
                    $middle = ($l + $r + 1) >> 1;
                    if ($nums[$middle] > $target) {
                        $r = $middle - 1;
                    } else {
                        $l = $middle;
                    }
                }
                $data[1] = $r;

            }
        }

        return $data;

    }
```

   