时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $hash = [];

        for ($i = 0, $count = count($nums1); $i < $count; $i++) {
            $hash[$nums1[$i]] = ($hash[$nums1[$i]] ?? 0) + 1;
        }

        $intersect = [];

        for ($i = 0, $count = count($nums2); $i < $count; $i++) {
            if (isset($hash[$nums2[$i]]) && --$hash[$nums2[$i]] >= 0) {
                $intersect[] = $nums2[$i];
            }
        }

        return $intersect;
    }
}
```