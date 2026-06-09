### 解题思路
此处撰写解题思路
php运用合并函数，排序函数。根本就不需要排序计算。果然不同语音有不同的优点
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        $arr=array_merge($nums1,$nums2);
        sort($arr);
        $num = count($arr);
        if($num%2){
            return $arr[$num/2];
        }
        return round(($arr[$num/2-1]+$arr[$num/2])/2,10);
    }
}
```