### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        $full = array_merge($nums1, $nums2);//merge arrays
        sort($full);//sort it with values
        $full_size = sizeof($full);
        if($full_size%2){//has remainder
            $m_key = floor($full_size/2);
            return $full[$m_key];
        }
        else{
            $m_key = $full_size/2;
            return ($full[$m_key] + $full[$m_key-1])/2;
        }
    }
}
```