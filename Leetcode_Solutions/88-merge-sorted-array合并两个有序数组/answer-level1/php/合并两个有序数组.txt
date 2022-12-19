双指针模式，考虑从大到小的方式。

class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer $m
     * @param Integer[] $nums2
     * @param Integer $n
     * @return NULL
     */
    function merge(&$nums1, $m, $nums2, $n) {
        $p = $m + $n - 1;
        while($n > 0) {
            if ($m <= 0 || $nums2[$n - 1] >= $nums1[$m - 1]) {
                $nums1[$p--] = $nums2[$n - 1];
                $n--;
            } else {
                $nums1[$p--] = $nums1[$m - 1];
                $m--;
            }
        }
        return;
    }
}