### 解题思路
该题是对二分法深入理解特别好的题。找到每个房屋离加热器的最短距离（即遍历房屋，通过二分法在全部加热器中查找离房屋最近的加热器），然后在所有距离中选出最大的一个即为结果。

### 说明
case: [282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923]
[823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612]
可验证二分法大于中间值的时候$rear = $mid;而不是$rear = $mid - 1;

二分法如果找不到的时候，目标值跟左右指针的值的关系很值得探索啊。
例如：[1,4]中查找0, 2, 5, 左右指针都是相等的。
不能简单粗暴的使用
```
return min(abs($house - $heaters[$front]), abs($house - $heaters[$rear]));
```


### 性能
执行用时 :156 ms, 在所有 PHP 提交中击败了16.67%的用户
内存消耗 :18.5 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $houses
     * @param Integer[] $heaters
     * @return Integer
     */
    function findRadius($houses, $heaters) {
        sort($houses);
        sort($heaters);

        $min_radius = 0;
        foreach ($houses as $house) {
            $radius = $this->getRadius($heaters, $house);
            //var_dump($radius);
            if ($radius > $min_radius) {
                $min_radius = $radius;
            }
        }

        return $min_radius;
    }

    public function getRadius($heaters, $house)
    {
        $radius = 0;
        $front = 0;
        $rear = count($heaters) - 1;
        while ($front < $rear) {
            $mid = intval(($front + $rear) / 2);
            if ($house > $heaters[$mid]) {
                $front = $mid + 1;
            } elseif ($house < $heaters[$mid]) {
                $rear = $mid;
            } else {
                return $radius;
            }
        }

        if ($heaters[$front] < $house) {
            $radius = $house - $heaters[$front];
        } else {
            if ($front == 0) {
                $radius = $heaters[$front] - $house;
            } else {
                $radius = min($heaters[$front] - $house, $house - $heaters[$front - 1]);
            }
        }

        return $radius;
    }   
}
```

### 参考
有很详细的注释，及评论区回复。
为什么c小于加热器时要考虑计算left和left-1最小值，为什么c大于加热器时可以直接计算。二分法不就是返回的是与当前值最相近的值了么

题解的二分法是在求 使得 heaters[pos] >= c 中最小的 pos （即house 右边最近 heater）。如果结果 heaters[pos] < c， 意味着house右边没有heater 。直接算就可以了。。
[二分查找解法Python](https://leetcode-cn.com/problems/heaters/solution/er-fen-cha-zhao-de-jie-fa-by-li-xian-sen/)