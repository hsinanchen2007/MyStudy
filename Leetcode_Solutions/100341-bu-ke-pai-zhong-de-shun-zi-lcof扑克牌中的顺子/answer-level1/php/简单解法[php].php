### 解题思路
不使用排序，当最大值减最小值小于等于5时，且这5张排没有重复的，那肯定是顺子。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function isStraight($nums) {
        $min=null;
        $max=null;
        $map=[];
        foreach($nums as $num){
            if($num==0) continue;
            if(isset($map[$num])) return false;
            $min = $min==null ? $num : min($min,$num);
            $max = $max==null ? $num : max($max,$num);
            $map[$num]=1;
        }
        return $max-$min+1<=5;
    } 
}
```