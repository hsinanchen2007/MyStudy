### 解题思路
如题

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $intersection = [];
        $dict = [];

        //先比较出两数组的长短
        $short = count($nums1) <= count($nums2) ? $nums1 : $nums2;
        $long = count($nums2) >= count($nums1) ? $nums2 : $nums1;

        //以短数组元素数作为基准制作字典
        $dict = array_count_values($short);
 
        //在长数组中查找
        foreach($long as $char) {
            if(!isset($dict[$char])) continue;
            elseif($dict[$char]>0) {
                $intersection[] = $char;
                $dict[$char]--;
            }
        }

        return $intersection;
    }
}
```