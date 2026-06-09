```
function merge(&$nums1, $m, $nums2, $n) {
    for ($i = 0; $i < $n; $i++) {
        $nums1[$m+$i] = $nums2[$i];
    }
    sort($nums1);
}

function merge(&$nums1, $m, $nums2, $n) {
    while ($n > 0) {
        if ($m <= 0 || $nums2[$n-1] >= $nums1[$m-1]) {
            $nums1[$m+$n-1] = $nums2[$n-1];
            $n--;
        } else {
            $nums1[$m+$n-1] = $nums1[$m-1];
            $m--;
        }
    }
}
```
