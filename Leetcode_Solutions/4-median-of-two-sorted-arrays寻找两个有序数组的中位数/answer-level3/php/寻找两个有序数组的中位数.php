class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        $temp = array_merge($nums1,  $nums2);
        sort($temp);
        $count = count($temp);
        $type = $count%2;
        if($type == 0) {
            $i = $count/2;
            return ($temp[$i]+$temp[$i-1])/2;

        } else {
             $i = ($count+1)/2;
            return $temp[$i-1];
        }
        
        
    }
}