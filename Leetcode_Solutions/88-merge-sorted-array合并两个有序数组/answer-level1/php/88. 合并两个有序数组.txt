### 解题思路
截取替换

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer $m
     * @param Integer[] $nums2
     * @param Integer $n
     * @return NULL
     */
    function merge(&$nums1, $m, $nums2, $n) {
        if (count($nums1) <$m+$n) return [];
        for($i = 0;$i < count($nums2);$i++){
            $nums1[$m]= $nums2[$i];
            $m = $m +1;
        }
        sort($nums1);
        return $nums1;
    }
}
```