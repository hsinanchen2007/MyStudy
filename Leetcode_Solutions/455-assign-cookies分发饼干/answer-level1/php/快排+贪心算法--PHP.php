### 解题思路
两个数组排序，挨个匹配，每次取一块饼干，满足条件小孩数量加1，不满足就跳过。

### 性能
执行用时 :68 ms, 在所有 PHP 提交中击败了91.49%的用户
内存消耗 :16.9 MB, 在所有 PHP 提交中击败了31.25%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $g
     * @param Integer[] $s
     * @return Integer
     */
    function findContentChildren($g, $s) {
        $child = $cookie = 0;
        sort($g);
        sort($s);

        while ($child < count($g) && $cookie < count($s)) {
            if ($g[$child] <= $s[$cookie]) {
                $child++;
            }

            $cookie++;
        }

        return $child;
    }
}
```