class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        //两个数组合并
        $arr = array_merge($nums1,$nums2);
        //对数组进行排序
        sort($arr);
        $count = count($arr);
        if ($count%2 == 1) {
            $num = $arr[(($count + 1)/2) - 1];
        } else {
            $num = ($arr[($count/2) - 1] + $arr[$count/2])/2;
        }
        return $num;
    }
}