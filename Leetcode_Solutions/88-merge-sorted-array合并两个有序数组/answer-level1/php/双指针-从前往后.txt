### 解题思路
1. p1指针指向nums1备份数组tmp的头；
2. p2指针指向nums2数组的头；
3. tmp[$p1] 与 $nums2[$p2] 比较大小，每次将小的重新放入$nums1中；
4. 注意不要忘记考虑tmp[$p1] 或者 $nums2[$p2] 为空的情况。

Tip: 多学习一下别人的写法，很简单优雅，值得学习，加油。

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
        $tmp = $nums1;
        $nums1 = [];
        $p1 = 0;
        $p2 = 0;
        $p = 0;
        while(isset($tmp[$p1]) && isset($nums2[$p2])) {
            $nums1[$p++] = ($tmp[$p1] <= $nums2[$p2]) ? $tmp[$p1++] : $nums2[$p2++];
        }
        if(isset($tmp[$p1])) {
            // for($i = $p1; $i < count($tmp); ++$i) {
            //     array_push($nums1, $tmp[$i]);
            // }
            $nums1 = array_merge($nums1, array_slice($tmp, $p1));
        }
        if(isset($nums2[$p2])) {
            $nums1 = array_merge($nums1, array_slice($nums2, $p2));
        }
        return $nums1;
    }
}
```