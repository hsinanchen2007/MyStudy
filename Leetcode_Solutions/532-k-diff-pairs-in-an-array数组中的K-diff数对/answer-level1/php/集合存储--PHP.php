### 解题思路

算法：
1. 遍历数组，遍历过的元素放到数组$visitor中
2. 定义差集$diff。
3. 因为$i - $j = $k，$j = $i - $k 如果$i - $k在$visitor中，那么$i - $k是满足要求的，加入$diff.
4. 因为$j + $k = $i, $i = $i + $k 如果$j + $k在$visitor中，那么$i是满足要求的，加入$diff. 

注意：可能出现重复元素，因为放在集合中，这里使用数组来模拟，需要去重。


### 性能
执行用时 :308 ms, 在所有 PHP 提交中击败了9.09%的用户
内存消耗 :17.3 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function findPairs($nums, $k) {
        if ($k < 0) return 0; 
        $diff = [];
        $visitor = [];

        foreach ($nums as $num) {
            if (in_array($num - $k, $visitor)) $diff[] = $num - $k;

            if (in_array($num + $k, $visitor)) $diff[] = $num;

            $visitor[] = $num;
        }

        return count(array_unique($diff));
    }
}
```