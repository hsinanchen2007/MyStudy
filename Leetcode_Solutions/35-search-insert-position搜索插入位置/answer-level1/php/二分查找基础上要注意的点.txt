二分查找算法：
0、先比较数组中间值和目标值，如果相等，则返回中间值的下标。
1、如果中间值大于目标值，则搜索在前半部分进行。
2、如果中间值小于目标值，则搜索在后半部分进行

这里要注意的点
0、如果要查找的值超过了数组的范围，比最小值小，比最大值大。传统的二分不会异常，但是这里会。
1、传统的二分找不到返回-1, 这里注意返回$head。

我的提交执行用时已经战胜 91.75 % 的 php 提交记录

```
function searchInsert($nums, $target) {
        $len = count($nums);
        if ($len < 1 OR $target < $nums[0]) {
            return 0;
        }

        $tail = $len - 1;

        if ($target > $nums[$tail]) {
            return $len;
        }

        while ($head <= $tail) {
            $mid = intval(($head + $tail) / 2);
            if ($target < $nums[$mid]) {
                $tail = $mid - 1;
            } elseif ($target > $nums[$mid]) {
                $head = $mid + 1;
            } else {
                return $mid;
            }
        }

        return $head;
    }

```
