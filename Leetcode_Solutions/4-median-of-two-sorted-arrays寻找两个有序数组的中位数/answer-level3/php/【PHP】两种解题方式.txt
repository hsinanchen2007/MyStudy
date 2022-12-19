```php []
/**
 * 简单式：
 * - 支持 $nums1, $nums2 为无序数组
 */
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays(array $nums1, array $nums2): float
    {
        $nums = array_merge($nums1, $nums2);
        sort($nums);

        $n = count($nums);
        $i = $n - 1;
        if ($n % 2 == 0) { //偶数
            $m = ($nums[$i / 2] + $nums[$i / 2 + 1]) / 2;
        } else {
            $m = $nums[($i + 1) / 2];
        }

        return $m;
    }
}
```
```php []
/**
 * 二分查找式
 * - $nums1, $nums2 必须为有序数组
 */
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays(array $nums1, array $nums2): float
    {
        $nums = $nums1;
        foreach ($nums2 as $nv2) {
            list($nums, $posi) = self::bisectionInsertionClassic($nums, $nv2); //循环进行查找插入
        }

        $n = count($nums);
        $i = $n - 1;
        if ($n % 2 == 0) { //偶数
            $m = ($nums[$i / 2] + $nums[$i / 2 + 1]) / 2;
        } else {
            $m = $nums[($i + 1) / 2];
        }

        return $m;
    }

    /**
     * 二分查找插入
     * @param array $sarr
     * @param integer $val
     * @return array
     */
    public static function bisectionInsertionClassic(array $sarr, int $val): array
    {
        $cnt = count($sarr);
        $low = 0;
        $high = $cnt - 1;
        while ($low <= $high) {
            $mid = ceil(($low + $high) / 2);
            $mval = $sarr[$mid];
            if ($val > $mval) {
                $low = $mid + 1;
            } else {
                $high = $mid - 1;
            }
        }
        for ($i = $cnt; $i > $low; $i--) {
            $sarr[$i] = $sarr[$i - 1];
        }
        $sarr[$low] = $val;

        return [$sarr, $low];
    }
}
```
