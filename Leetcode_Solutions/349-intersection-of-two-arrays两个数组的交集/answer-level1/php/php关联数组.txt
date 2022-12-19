思路：利用php的关联数组，2遍循环完成
```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {
        $arr=[];
        
        foreach($nums1 as $item){
            $arr[$item]=$item;
        }

        $ret=[];
        foreach($nums2 as $item){
            if(isset($arr[$item]))
                $ret[$item]=$item;
        }

        return $ret;
    }
}
```
