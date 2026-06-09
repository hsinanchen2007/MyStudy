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
        $m = count($nums1);
        $n = count($nums2);
        //判断当其中一个为空时直接获取另一个中的中间数
        if($m == 0){
            if($n % 2 == 0){
                return ($nums2[$n/2-1] + $nums2[$n/2])/2;
            }else{
                return $nums2[($n-1)/2];
            }
        }elseif($n == 0){
            if($m % 2 == 0){
                return ($nums1[$m/2-1] + $nums1[$m/2])/2;
            }else{
                return $nums1[($m-1)/2];
            }
        }
        
        $left = floor(($m+$n+1)/2);
        $right = floor(($m+$n+2)/2);
        //将奇数和偶数情况合并
        return ($this->searchMedian($nums1,0,$m-1,$nums2,0,$n-1,$left)+$this->searchMedian($nums1,0,$m-1,$nums2,0,$n-1,$right))/2.0;
    }

    function searchMedian($nums1,$start1,$end1,$nums2,$start2,$end2,$median){
        $len1 = $end1-$start1+1;
        $len2 = $end2-$start2+1;
        //保证$nums1元素数少于$num2，确保$nums1先为空
        if($len1 > $len2){
            return $this->searchMedian($nums2,$start2,$end2,$nums1,$start1,$end1,$median);
        }
        //当$len=0时在$nums2中直接取出需要的值
        if($len1 == 0){return $nums2[$start2+$median-1];}
        //当$median=1时获取两个数组中最小的值
        if($median == 1){return min($nums1[$start1],$nums2[$start2]);}

        $i = $start1 + min($len1,floor($median/2))-1;
        $j = $start2 + min($len2,floor($median/2))-1;
        
        if($nums1[$i]<$nums2[$j]){
            return $this->searchMedian($nums1,$i+1,$end1,$nums2,$start2,$end2,$median-($i-$start1+1));
        }else{
             return $this->searchMedian($nums1,$start1,$end1,$nums2,$j+1,$end2,$median-($j-$start2+1));
        }
    }
}
```