# 方法一: 暴力解题 
- 时间复杂度O(n*m) 空间复杂度O(n*m)
- 需要每个元素进行对比即可,简单又暴力.
- 但是执行时间太感人.
```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {
        $a1 = count($nums1);
        $b1 = count($nums2);

        $has = [];

        for ($i=0;$i<$a1;$i++) {
            for ($j=0;$j<$b1;$j++) {
                if ($nums1[$i] == $nums2[$j] && !in_array($nums2[$j],$has)) {
                    $has[] = $nums2[$j];
                }
            }
        }
        return $has;
    }
}
```
# 方法二: Hash表 
- 时间复杂度O(m+n) 空间复杂度O(m+n)
- 遍历第一个数组,使用hash记录
- 第二个数组遍历时,判断是否在hash表中,在则记录并删除此key,不在则跳过
![image.png](https://pic.leetcode-cn.com/6ad67169df133371adde836e84b238fb7f487ab83340e2baa7e7e77b92288f6a-image.png)
```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {

        $a1 = count($nums1);
        $b1 = count($nums2);

        $hash = $has = [];
        # 生成hash
        for ($i=0;$i<$a1;$i++) {
            $hash[$nums1[$i]] = 0;
        }

        # 这个地方思考了下,不需要这样判断了,直接用下面的方法删除掉hash的key即可
        // for ($j=0;$j<$b1;$j++) {
        //     if (isset($hash[$nums2[$j]]) && !in_array($nums2[$j], $has)) {
        //         $has[] = $nums2[$j];
        //     }
        // }
        # 遍历并且判断是否存在该下标,存在记录并删除key
        for ($j=0;$j<$b1;$j++) {
            if (isset($hash[$nums2[$j]])) {
                $has[] = $nums2[$j];
                unset($hash[$nums2[$j]]);
            }
        }
        # 返回记录的数组
        return $has;
    }
}
```
