看了官方解答才恍然大悟,有时确实需要点播才能悟透算法的奇妙.
整个题目可以化简成数组个数内的判断标识的操作,例 [3,1,-1,1,2] 5个元素,判断这5个元素的为正的连续性,使用下标做出答案
前面的判断就不说了,理解很容易
下面的请看具体注释
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        $out = 1;
        if (empty($nums)) {
            return $out;
        }
        $count = count($nums);
        if ($count==1 && $nums[0] == 1) {
            return 2;
        }
        if (!in_array(1, $nums)) {
            return $out;
        }
        # 将数组中为负||0||超出数组个数的值转换成1,以便下面做正负标识使用
        for ($i=0; $i<$count; $i++) {
            if ($nums[$i] <= 0 || $nums[$i] > $count) {
                $nums[$i] = 1;
            }
        }
        # 将数组中第a个元素如果存在这个下标则将这个下标标识为存在该数组.
        for ($i=0; $i<$count; $i++) {
            $a = abs($nums[$i]);
            if ($a == $count) {
                $nums[0] = -abs($nums[0]);
            } else {
                $nums[$a] = -abs($nums[$a]);
            }
        }
        # 找出下标对应的值为负数的时候说明存在则跳过,如果为正则代表该下标是最小整数,因为下标是连续的
        for ($i=1; $i<$count; $i++) {
            if ($nums[$i] > 0) {
                return $i;
            }
        }
        # 如果下标0的元素为正数则代表数组中最大的值小于数组总合,则输出当前总合
        if ($nums[0] > 0) {
            return $count;
        }
        # 如果数组全部为负数,则代表数组是一个连续元素,则结果为总合+1
        return $count+1;
    }
}
```
