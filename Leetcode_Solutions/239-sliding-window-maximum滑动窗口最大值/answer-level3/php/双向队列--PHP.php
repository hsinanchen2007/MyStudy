### 解题思路
采用双端队列。
**双端队列（deque，double-ended queue），是一种具有队列和栈的性质的数据结构，可以在队列任意一端入队和出队。**

算法：遍历数组，把当前元素的下标在队尾入队，如果队列长度达到了$k, 从队头出队一个元素。如果队列不为空，并且当前元素大于队尾索引对应的元素，就一直出队。把队头元素加入结果集。

**注意：把元素下标加入队列，而不是元素本身，是为了方便检查队列长度是否达到了$k。用下标加偏移量来计数长度及其方便。**

如果队列中放元素本身，下面这个case就会有问题，代码可参考文末
```
[1,3,1,2,0,5]
3
```

### 性能
执行用时 :52 ms, 在所有 PHP 提交中击败了97.96%的用户
内存消耗 :23 MB, 在所有 PHP 提交中击败了51.52%的用户


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function maxSlidingWindow($nums, $k) {
        $window = [];
        $res = [];
        for ($i = 0; $i < count($nums); $i++) {
            if ($i >= $k + $window[0]) array_shift($window);

            while ($window && $nums[end($window)] <= $nums[$i]) {
                array_pop($window);
            }

            $window[] = $i;

            if ($i >= $k - 1) {
                $res[] = $nums[$window[0]];
            }
        }

        return $res;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N) [不准确]
- 空间复杂度 O(N)

### 错误代码
把元素本身放入队列中，存在bug
```
function maxSlidingWindow($nums, $k) {
        $window = [];
        $res = [];
        for ($i = 0; $i < count($nums); $i++) {
            if (count($window) >= $k) array_shift($window);

            while ($window && end($window) <= $nums[$i]) {
                array_pop($window);
            }

            $window[] = $nums[$i];

            if ($i >= $k - 1) {
                $res[] = $window[0];
            }
        }

        return $res;
    }
```


### 参考
[https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/](https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/)