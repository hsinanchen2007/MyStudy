### 解题思路
见代码

### 代码

```php
class Solution {
    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        //异常条件判断
        if(count($arr)==0 || $k>count($arr) || $k==0) return [];
        
        //第一次快排
        $low=0;
        $high = count($arr)-1;
        $index = $this->quickSort($arr,$low,$high);
        
        //排序后index位置与k-1不相等
        while($index != $k-1){
            //如果index小于k-1,那么就从index+1位置处排序
            if($index<$k-1){
                $low=$index+1;
                $index = $this->quickSort($arr,$low,$high);
            }
            //如果index大于k-1，那么就从index-1位置处排序
            if($index>$k-1){
                $high = $index-1;
                $index = $this->quickSort($arr,$low,$high);
            }
        }

        return array_slice($arr,0,$k);
    }

    function quickSort(&$arr,$low,$high){
        //整段都是快排，不懂的自己在纸上画画
        $pivot = $arr[$low];
        while ($low<$high){
            while ($low<$high && $arr[$high]>=$pivot){
                $high--;
            }
            $arr[$low] = $arr[$high];
            while ($low<$high && $arr[$low]<=$pivot){
                $low++;
            }
            $arr[$high] = $arr[$low];
        }
        $arr[$low]=$pivot;
        return $low;
    }
}
```