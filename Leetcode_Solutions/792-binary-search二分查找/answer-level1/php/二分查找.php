### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        if(empty($nums) ){
            return -1;
        }
        $count=count($nums);
        $left=0;
        $right=$count-1;
        while($left<=$right){
            $mid=floor($left+($right-$left)/2);
            if($nums[$mid]==$target){
                return $mid;
            }elseif($nums[$mid]<$target){
                $left=$mid+1;
            }else{
                $right=$mid-1;
            }
        }
        return -1;             ;
    }
}
```