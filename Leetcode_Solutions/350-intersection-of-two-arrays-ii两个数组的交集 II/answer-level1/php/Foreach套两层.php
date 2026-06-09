### 解题思路
Foreach套两层

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $res_arr = [];
        foreach((array)$nums1 as $key1 =>$val1){
            foreach((array)$nums2 as $key2 =>$val2){
                if($val1 == $val2){
                    $res_arr[] = $val1;
                    unset($nums2[$key2]);
                    break;
                }
            }
        }
        return $res_arr;
    }
}
```