### 解题思路
我写的很容易看懂，这个题就是归并排序的合并两个数组部分，但是我认为赋值临时数组这里应该有更好的解法。

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
        $tmp = [];
        $i = 0;
        $j = 0;
        
        while($i < $m && $j < $n){
            if($nums1[$i] < $nums2[$j]){
                $tmp[] = $nums1[$i++];
            }else{
                $tmp[] = $nums2[$j++];
            }
        }
        
        while($i < $m){
            $tmp[] = $nums1[$i++];
        }
        
        while($j < $n ){
            $tmp[] = $nums2[$j++];
        }
        
        for($k = 0;$k<count($tmp);$k++){
            $nums1[$k] = $tmp[$k];
        }
        
        return $nums1;
    }
}
```