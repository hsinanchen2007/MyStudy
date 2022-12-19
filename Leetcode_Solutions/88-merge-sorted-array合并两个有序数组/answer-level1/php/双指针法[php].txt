### 解题思路
官方题解第2个

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
        $i=$j=$p=0;
        $nums1_copy = $nums1;
        while($i<$m && $j<$n){
            $nums1[$p++] = $nums1_copy[$i]<$nums2[$j] ? $nums1_copy[$i++] : $nums2[$j++];
        }
        if($i<$m){
            array_splice($nums1,$i+$j,$m-$i,array_slice($nums1_copy,$i));
        }
        if($j<$n){
            array_splice($nums1,$i+$j,$n-$j,array_slice($nums2,$j));
        }
        $nums1 = array_slice($nums1,0,$m+$n);
    }
}
```