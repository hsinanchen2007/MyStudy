### 解题思路
先合并再排序
时间复杂度较高

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
        $nums1 = array_slice($nums1, 0, $m);
        $nums1 = array_merge($nums1, $nums2);
        sort($nums1);
        return $nums1;
    }
}
```