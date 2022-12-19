时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {
        $hash = [];

        for ($i = 0, $count = count($nums1); $i < $count; $i++) {
            $hash[$nums1[$i]] = '';
        }

        $intersect = [];

        for ($i = 0, $count = count($nums2); $i < $count; $i++) {
            if (isset($hash[$nums2[$i]])) {
                $intersect[] = $nums2[$i];
                unset($hash[$nums2[$i]]);
            }
        }

        return $intersect;
    }
}
```