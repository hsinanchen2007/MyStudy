### 解题思路


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        $arr = array_merge($nums1,$nums2);
        sort($arr);
        $num = count($arr);
        if($num%2==1){
            return $arr[($num-1)/2];
        }else{
            return ($arr[$num/2]+$arr[($num-2)/2])/2;
        }
    }
}
```