### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function findKthLargest($nums, $k) {
      $left=0;
      $count=count($nums);
      $right=$count-1;
      $target=$count-$k;

      while(true){
          $index=$this->partition($nums,$left,$right);
          if($index==$target){
            return $nums[$index];
          }else{
              if($index<$target){
                $left=$index+1;
              }else{
                  $right=$index-1;
              }
          }

      }

    }
    function partition(&$nums,$left,$right){
        $prov=$nums[$left];
        $j=$left;
        for($i=$left+1;$i<=$right;$i++){
            if($nums[$i]<$prov){
                $j++;
                $this->swap($nums,$i,$j);
            }
        }
        $this->swap($nums,$left,$j);
        return $j;
    }
    function swap(&$nums,$i,$j){
        $temp=$nums[$i];
        $nums[$i]=$nums[$j];
        $nums[$j]=$temp;
    }









}
```