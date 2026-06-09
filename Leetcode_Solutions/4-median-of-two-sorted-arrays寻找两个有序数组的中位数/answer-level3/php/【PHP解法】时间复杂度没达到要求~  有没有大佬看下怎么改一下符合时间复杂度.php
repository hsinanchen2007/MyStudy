class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        $com_arr = array_merge($nums1,$nums2);
        asort($com_arr);
        $com_arr = array_values($com_arr);
        if(count($com_arr)%2 == 0){
            //偶数
            $num = count($com_arr)/2;
            $result = ($com_arr[$num] + $com_arr[$num-1])/2;
        }else{
            //奇数
            $num = floor(count($com_arr)/2);
            $result = $com_arr[$num];
        }
        return floatval($result);
    }
}