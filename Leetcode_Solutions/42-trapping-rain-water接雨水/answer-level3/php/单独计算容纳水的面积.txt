### 解题思路
先将整个列表分组
从左边开始，值大于等于左边即为一组,当前的右边即为下一组的左边,
[0,1,0,2,1,0,1,3,2,1,2,1] 可分组为 [[0,1], [1,0,2],[2,1,0,1,3],[3,2,1,2,1]]
对于最后一组 右边小于左边，可以看做从右边开始的分组，整个拿出来算面积
[0,1] 面积为 (0 - 1)0 = 0
[1,0,2] 面积为 (1 - 0)1 + (1 - 2)0 = 1
[2,1,0,1,3] 面积为 (2-1)1 + (1-1)0 + (2-0)2 + (2-1)1 + (2-3)0 = 4
[3,2,1,2,1] 处理成从右往左再来一次 分组为 [[1,2], [2,1,2], [2,3]]
[1,2] 面积为 (1-2)0 = 0
[2,1,2] 面积为 (2-1)1 + (2-2)0 = 1
[2,3] 面积为 (2-3)0 = 0

总面积为 1 + 4 + 1 = 6
### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $map = [];
        $left = $right = -1;
        foreach ($height as $i => $h) {
            if (-1 === $left) {
                $left = $i;
                continue;
            }
            $right = $i;

            if ($h >= $height[$left]) {
                $map[] = [$left, $right];
                $left = $i;
                $right = -1;
            }
        }
        $map[] = [$left, $right];
        $result = 0;
        foreach ($map as [$left, $right]) {
            if (-1 === $left || -1 === $right) {
                continue;
            }
            $curArea = 0;
            if ($height[$left] > $height[$right]) {
                $newHeight = [];
                for ($j = $right; $j >= $left; $j--) {
                    $newHeight[] = $height[$j];
                }
                $curArea = $this->trap($newHeight);
            } else {
                for ($i = $left + 1; $i < $right; $i++) {
                    $area = $height[$left] - $height[$i];
                    $curArea += $area > 0 ? $area : 0;
                }
            }
            $result += $curArea;
        }
        return $result;
    }
}
```