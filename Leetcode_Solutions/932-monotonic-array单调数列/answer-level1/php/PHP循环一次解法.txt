- 添加两个变量
- 遍历一次数组
- 优化效率
- 时间复杂度O(n),空间复杂度O(1)
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Boolean
     */
    function isMonotonic($A) {
        if (empty($A)) {
            return false;
        }
        $isHeight = $isLow = 0;
        $count = count($A);
        for ($i=0;$i<$count;$i++) {
            if ($i == $count-1) {
                break;
            }
            $r = $i+1;
            if ($A[$i] > $A[$r]) {
                $isLow += 1;// 单调递减
            } elseif ($A[$i] < $A[$r]) {
                $isHeight += 1; // 单调递增
            }
            # 变量都不为零直接返回false
            if ($isLow != 0 && $isHeight != 0) {
                return false;
            }
        }
        # 判断是否单调
        return $isLow == 0 || $isHeight == 0 ? true : false;
    }
}
```
