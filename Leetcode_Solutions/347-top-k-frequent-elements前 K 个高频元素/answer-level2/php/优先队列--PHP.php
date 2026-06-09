### 解题思路
使用PHP原生的优先队列数据结构SplPriorityQueue

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function topKFrequent($nums, $k) {
        $counts = array_count_values($nums);

        $spq = new SplPriorityQueue();
        foreach ($counts as $num => $count) {
            $spq->insert($num, $count);
        }

        $res = [];
        for ($i = 0; $i < $k; $i++) {
            $res[] = $spq->extract();
        }

        return $res;
    }
}
```

### 性能
执行用时 :40 ms, 在所有 PHP 提交中击败了52.38%的用户
内存消耗 :20.3 MB, 在所有 PHP 提交中击败了14.29%的用户

### 算法复杂度

### 参考
[https://leetcode-cn.com/problems/top-k-frequent-elements/solution/php-jie-fa-you-xian-ji-dui-lie-by-andfly/](https://leetcode-cn.com/problems/top-k-frequent-elements/solution/php-jie-fa-you-xian-ji-dui-lie-by-andfly/)