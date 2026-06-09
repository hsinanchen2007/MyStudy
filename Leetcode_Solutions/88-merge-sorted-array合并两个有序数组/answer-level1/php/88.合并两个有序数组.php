### 解题思路
此处撰写解题思路

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
        if($m == 0){
		    $nums1 = $nums2;
		    return $nums1;
	    }
        $len = count($nums1);
        while($m >= 0 && $n > 0){
            if($nums1[$m-1] > $nums2[$n-1]){
                $tmp = $nums1[$m-1];
                $nums1[$m-1] = $nums1[$len-1];
                $nums1[$len-1] = $tmp;
                $m--;
            }else{
                $nums1[$len-1] = $nums2[$n-1];
                $n--;
            }
            $len--;
        }
        return $nums1;
    }
}
```