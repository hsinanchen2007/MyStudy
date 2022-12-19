### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSubArray($nums) {
        $count=count($nums);
        if($count<=1){
            return $nums[0];
        }
        return $this->maxSubArrayRecursion($nums,0,$count-1);

    }
    function maxSubArrayRecursion($nums,$l,$r){
        if($l==$r){
            return $nums[$l];
        }elseif($l<$r){
            $mid=floor($l+($r-$l)/2);
            $ln=$this->maxSubArrayRecursion($nums,$l,$mid);
            $rn=$this->maxSubArrayRecursion($nums,$mid+1,$r);

            $sum=0;
            $lsum=$nums[$mid];
            for($i=$mid;$i>=$l;$i--){
                $sum += $nums[$i];
                $lsum=max($lsum,$sum);
            }
            $sum=0;
            $rsum=$nums[$mid+1];
            for($i=$mid+1;$i<=$r;$i++){
                $sum += $nums[$i];
                $rsum=max($rsum,$sum);
            }
            $coss=$lsum+$rsum;
            return max($ln,$rn,$coss);
            
        }else{
            return 0;
        }
    }
}
```