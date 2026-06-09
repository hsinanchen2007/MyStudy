### 解题思路
参考了官方题解和网友题解。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function maxSlidingWindow($nums, $k) {
        // 使用双向队列，该数据结构可以从两端以常数时间压入 / 弹出元素
        // 双端队列和普通队列最大的不同在于，它允许我们在队列的头尾两端都能在O(1) 的时间内进行数据的查看、添加和删除。
        $length = count($nums);
        if ($length == 0) {
            return [];
        }

        // 维护一个窗口，存储元素下标
        $window = [];
        $result = [];
        // 算法非常直截了当：
        //处理前 k 个元素，初始化双向队列。
        //遍历整个数组。在每一步 :
        //清理双向队列 :
        //  - 只保留当前滑动窗口中有的元素的索引。
        //  - 移除比当前元素小的所有元素，它们不可能是最大的。
        //将当前元素添加到双向队列中。
        //将 deque[0] 添加到输出中。
        //返回输出数组。
        foreach ($nums AS $key => $value) {
            // 窗口已建立，最左侧的元素已不属于窗口，弹出最左侧元素
            if ($key >= $k + $window[0]) {
                array_shift($window);
            }

            while ($window && $nums[end($window)] <= $value) {
                array_pop($window);
            }

            $window[] = $key;
            if ($key >= $k - 1) {
                $result[] = $nums[$window[0]];
            }
        }

        return $result;
    }
}
```