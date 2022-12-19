思路：利用php关联数组，3遍循环搞定
```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $arr1=[];
        
        foreach($nums1 as $item){
            if(isset($arr1[$item]))
                $arr1[$item]+=1;
            else
                $arr1[$item]=1;
        }

        $arr2=[];
        foreach($nums2 as $item){
            if(isset($arr2[$item]))
                $arr2[$item]+=1;
            else
                $arr2[$item]=1;
        }

        $ret=[];
        foreach($arr1 as $k=>$v){
            if(isset($arr2[$k])){
                $n=min([$v,$arr2[$k]]);
                for($i=0;$i<$n;$i++){
                    $ret[]=$k;
                }
            }
        }

        return $ret;
    }
}
```
