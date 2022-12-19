空间换时间方法
执行用时 : 12 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 : 15 MB, 在所有 PHP 提交中击败了11.11%的用户
1.将母数组找出每个元素后面是否有比自己大的值,组成key=>value形式
2.遍历子数组映射相应的值,未映射到则代表没有最大值给出-1
```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function nextGreaterElement($nums1, $nums2) {
        $count1 = sizeof($nums1);
        $count2 = sizeof($nums2);
        $s = [];
        $a = [];
        for ($i=0;$i<$count2;$i++) {
            /**
             * 这里是制作映射hash表的地方
             * 如果栈顶值小于下个元素的值,则将栈顶值出栈当key 下个元素值当value
             */
            while (!empty($s) && $s[count($s)-1] < $nums2[$i]) {
                $tmp = array_pop($s);
                $a[$tmp] = $nums2[$i];
            }
            # 将母数组元素顺序入栈
            $s[] = $nums2[$i];
        }
        $out = [];
        for ($i=0;$i<$count1;$i++) {
            if (isset($a[$nums1[$i]])) {
                $out[] = $a[$nums1[$i]];
            } else {
                $out[] = -1;
            }
        }
        return $out;
    }
}
```
