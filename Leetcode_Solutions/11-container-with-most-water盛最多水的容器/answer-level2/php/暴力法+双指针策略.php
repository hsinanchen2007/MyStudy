### [THINKING]
- 两条垂直的线段会与x轴围成一个矩形区域
    - 其中一个较短的线段作为矩形的宽 min($height[$i],$height[$j])
    - 两个线段间距会作为矩形的长度   $j-$i
- 所以如果想让装水更多，就是求矩形面积最大

- 暴力法
    - 双层循环遍历所有的情况，然后计算比较大小。
    - O(n^2)时间复杂度，计算 n(n-1)/2种高度的面积。
    - O(1)  空间复杂度，使用恒定的额外空间。
- 双指针策略
    - 一个指向开头，一个指向结尾
    - 为了面积最大化
        - 当我们两个指针位置的面积计算后
        - 需要移动其中一个指针的位置
        - 那么，我们其实是看两个指针指向的值谁小，移动谁
    - 解释
        - 一开始就已经把指针定义在两端，如果短指针不动，而把长指针向着另一端移动，两者的距离已经变小了，
        - 无论会不会遇到更高的指针，结果都只是以短的指针来进行计算。 故移动长指针是无意义的
### [CODING]
```
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
     // 暴力法 会超时
    function maxArea($height) {
        $size = count($height);
        // 必须要两个线段以上
        if($size < 2 ) return 0;
        $max  = 0;
        // 尝试所有的情况
        for($i=0; $i<$size; $i++) {
            for($j=$i+1; $j<$size; $j++) {
                // 比较最大值
                $max = max($max,min($height[$i],$height[$j]) * ($j-$i));
            }
        }
        return $max;
    }

    // 双指针法
    // 执行用时 :44 ms, 在所有 php 提交中击败了42.29%的用户
    // 内存消耗 :16.6 MB, 在所有 php 提交中击败了5.88%的用户
    function maxArea2($height) {
        $size = count($height);
        // 必须要两个线段以上
        if($size < 2 ) return 0;
        $max  = 0;
        $left = 0;
        $right= $size-1;
        while($left < $right) {
            $max = max($max, min($height[$left],$height[$right]) * ($right-$left));
            if($height[$left] < $height[$right]) {
                $left++;
            }else{
                $right--;
            }
        }
        return $max;
    }
}
$obj    = new Solution();
$height = [1,8,6,2,5,4,8,3,7];
$res    = $obj->maxArea2($height);
var_dump($res);

```
