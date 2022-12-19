- hash表建立并计数
- 遍历第二个数组
- 计数大于1,则将值减一.等于1将该key移除
```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $hash = $out = [];
        $count = count($nums1);
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$nums1[$i]])) {
                $hash[$nums1[$i]] = 1;
            } else {
                $hash[$nums1[$i]] += 1;
            }
        }
        for ($i=0;$i<count($nums2);$i++) {
            if (isset($hash[$nums2[$i]])) {
                $out[] = $nums2[$i];
                if ($hash[$nums2[$i]] > 1) {
                    $hash[$nums2[$i]] -= 1;
                } elseif ($hash[$nums2[$i]] == 1) {
                    unset($hash[$nums2[$i]]);
                }
            }
        }
        return $out;
    }
}
```
