解题思路：利用php函数，合并数组然后排序，最后提取中间的数值计算中位数

```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        //数组合并，合并到$nums1
        $nums1 = array_merge($nums1,$nums2);

        sort($nums1);
        $length = count($nums1);
        
        if(($length % 2) == 1){//基数就取中间的
           $idx= ($length-1)/2;
           return $nums1[$idx];
        }
        else{//偶数提取中间2个的平均数
            $_left = $length/2 -1;
            return ($nums1[$_left] + $nums1[$_left+1]) / 2;
        }
    }
}
```
