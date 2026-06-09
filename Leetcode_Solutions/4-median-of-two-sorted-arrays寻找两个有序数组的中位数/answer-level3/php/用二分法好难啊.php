学的 windliang 的解法四，好难呀好难
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/

```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2)
    {
        $aCount = count($nums1);
        $bCount = count($nums2);
        if ($aCount > $bCount) {
            // 确保第二个数组比第一个长
            return $this->findMedianSortedArrays($nums2, $nums1);
        }
        $aCutPositionMin = 0; // 数组a的最小划分点位置，不是下标
        $aCutPositionMax = $aCount; // 数组a的最大划分点位置
        // 划分点的做用找出某个点，使其左边的数字总数和右边的数字总数一样，由于奇偶性原因，划分点有时在数字之间有时在数字上
        while ($aCutPositionMin <= $aCutPositionMax) {
            $aCutPosition = floor(($aCutPositionMin + $aCutPositionMax) / 2); // 二分法取一个划分点
            $bCutPosition = floor(($aCount + $bCount + 1) / 2 - $aCutPosition); // 用公式计算出数组b的划分点位置
            if (
                $bCutPosition != 0
                &&
                $aCutPosition != $aCount
                &&
                $nums2[$bCutPosition - 1] > $nums1[$aCutPosition]
            ) {
                // 如果b划分点不是最左且a划分点不是最右且b划分点左边的数大于a划分点上的数，就表明a划分点需要往右划
                $aCutPositionMin = $aCutPosition + 1;
            } elseif (
                $aCutPosition != 0
                &&
                $bCutPosition != $bCount
                &&
                $nums1[$aCutPosition - 1] > $nums2[$bCutPosition]
            ) {
                // 如果a划分点不是最左且b划分点不是最右且a划分点左边的数大于b划分点上的数，就表明a划分点需要往左划
                $aCutPositionMax = $aCutPosition - 1;
            } else {
                // 此时ab两个划分点右边最小的数字大于等于左边最大的数字或者ab划分点已经达到了某一个边界，需要进一步讨论
                $maxLeft = 0; // 左中位数（因为奇偶性，中位数可能是两数之和除以二）
                if ($aCutPosition == 0) {
                    // a划分点在最左，说明左中位数在b划分点左边
                    $maxLeft = $nums2[$bCutPosition - 1];
                } elseif ($bCutPosition == 0) {
                    // b划分点在最左，说明左中位数在a划分点左边
                    $maxLeft = $nums1[$aCutPosition - 1];
                } else {
                    // ab划分点都不在最左，说明左中位数是两划分点左边最大的那个数
                    $maxLeft = max($nums2[$bCutPosition - 1], $nums1[$aCutPosition - 1]);
                }
                if (($aCount + $bCount) % 2 == 1) {
                    // 如果两数组总数是奇数，那么中位数就已经得到，可以直接返回
                    return $maxLeft;
                }
                $minRight = 0; // 右中位数
                if ($aCutPosition == $aCount) {
                    // 如果a划分点在最右，说明右中位数在b划分点右边
                    $minRight = $nums2[$bCutPosition];
                } elseif ($bCutPosition == $bCount) {
                    // 如果b划分点在最右，说明右中位数在a划分点右边
                    $minRight = $nums1[$aCutPosition];
                } else {
                    // ab划分点都不在最右，说明右中位数是两划分点右边最小的那个数
                    $minRight = min($nums2[$bCutPosition], $nums1[$aCutPosition]);
                }
                // 如果两数组总数是偶数，那么中位数就计算一下
                return ($maxLeft + $minRight) / 2;
            }
        }
        return 0;
    }
}
```

