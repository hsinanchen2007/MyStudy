有一种简单方法,先将数组原地平方再排序,暂时先忽略这种方法
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortedSquares($A) {
        $count = count($A);
        $j = 0;
        # 查找非负位置
        while ($j < $count && $A[$j] < 0) {
            $j++;
        }
        # 给出非负左边位置
        $i = $j - 1;
        # 新开辟一块数组内存
        $out = [];
        # 同时遍历非负数和负数两侧指针对称的部分做判断,入数组
        while ($i >= 0 && $j < $count) {
            if ($A[$i] * $A[$i] < $A[$j] * $A[$j]) {
                $out[] = $A[$i] * $A[$i];
                $i--;
            } else {
                $out[] = $A[$j] * $A[$j];
                $j++;
            }
        }
        # 负数那一侧多,这步直接平方后入数组
        while ($i>=0) {
            $out[] = $A[$i] * $A[$i];
            $i--;
        }
        # 非负数那一侧多,这步直接平方后入数组
        while ($j<$count) {
            $out[] = $A[$j] * $A[$j];
            $j++;
        }

        return $out;
    }
}
```
