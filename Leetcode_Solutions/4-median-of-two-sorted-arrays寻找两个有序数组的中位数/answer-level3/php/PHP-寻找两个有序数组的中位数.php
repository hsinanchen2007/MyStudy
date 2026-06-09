### 解题思路
1 善用PHP函数
2 将两个数组合并，然后取中间位置索引计算即可

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        $arr = array_merge($nums1, $nums2); // 将两个数组进行合并.相同的key,则后面的元素会覆盖前面一个元素
        sort($arr);
        $tmp = count($arr)/2;
        $mid = (int)floor($tmp); // 索引向下取整
        $midNumber = is_int(count($arr)/2) ? ($arr[$mid] + $arr[$mid-1]) / 2 : $arr[$mid];
        return $midNumber;
    }
}
```