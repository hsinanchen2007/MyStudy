### 解题思路
通过两点之间的俄距离公式计算并存储距离。

计算两点直接距离公式：
已知两点：p1(x1, y1) p2(x2, y2) 
p1和p2距离平方 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 -y2)


算法：
1. 遍历每一个点。
2. 计算第一个点与剩余点的距离，存在map中，key为距离、value为数量。
3. 如果map中存在距离，回旋镖的数量加上这个距离的2倍。【因为可以交换】
4. 移动到下一个点，重复2、3
5. 返回总数量

### 性能
执行用时 :280 ms, 在所有 PHP 提交中击败了61.54%的用户
内存消耗 :15.8 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $points
     * @return Integer
     */
    function numberOfBoomerangs($points) {
        $map = [];
        $count = 0;
        for ($i = 0; $i < count($points); $i++) {
            $map = [];
            for ($j = 0; $j < count($points); $j++) {
                if ($i == $j) {
                    continue;
                }
                $dist = pow(($points[$j][0] - $points[$i][0]), 2) + pow(($points[$j][1] - $points[$i][1]), 2);
                if (isset($map[$dist])) {
                    $count += $map[$dist] * 2;
                    $map[$dist]++;
                } else {
                    $map[$dist] = 1;
                }
            }
        }

        return $count;
    }
}
```

### 总结
有问题的代码中发现，运算符优先级，!== 大于 =
```
                $dist = pow(($points[$j][0] - $points[$i][0]), 2) + pow(($points[$j][1] - $points[$i][1]), 2);
                if (($key = array_search($dist, $map)) !== false) {
                    $count += $map[$key] * 2;
                    $map[$key]++;
                } else {
                    $map[] = $dist;
                }
```

### 参考
[Java实现](https://leetcode-cn.com/problems/number-of-boomerangs/solution/447-hui-xuan-biao-de-shu-liang-by-en-zhao/)