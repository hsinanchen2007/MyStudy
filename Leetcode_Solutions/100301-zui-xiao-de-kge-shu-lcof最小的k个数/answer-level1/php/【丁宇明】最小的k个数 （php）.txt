### 解题思路

快速排序法，特别针对了该题做了改动。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        // 快速排序
        # $this->quickSort($arr, 0, count($arr)-1);
        # return array_slice($arr, 0 , $k);
        // 快速排序（针对题目优化）
        $this->quickSortTopic($arr, 0, count($arr)-1, $k);
        return array_slice($arr, 0 , $k);
    }

    ## 快速排序
    function quickSort(&$arr, $l, $r) {
        if($l < $r){
            $i = $l;
            $j = $r;
            $x = $arr[$i];
            while($i < $j){
                 while($i < $j && $arr[$j] >= $x) 
                    $j--;  // 从右向左找第一个小于x的数
                 if($i < $j) 
                    $arr[$i++] = $arr[$j];
                 while($i < $j && $arr[$i] <= $x) 
                    $i++;   // 从左向右找第一个大于x的数
                 if($i < $j) 
                    $arr[$j--] = $arr[$i];
            }
            $arr[$i] = $x;
            $this->quickSort($arr, $l, $i-1); /* 递归调用 */
            $this->quickSort($arr, $i+1, $r); /* 递归调用 */
        }
    }

    ## 快速排序（针对题目优化）
    function quickSortTopic(&$arr, $l, $r, $k) {
        if($l < $r){
            $i = $l;
            $j = $r;
            $x = $arr[$i];
            while($i < $j){
                 while($i < $j && $arr[$j] >= $x) 
                    $j--;  // 从右向左找第一个小于x的数
                 if($i < $j) 
                    $arr[$i++] = $arr[$j];
                 while($i < $j && $arr[$i] <= $x) 
                    $i++;   // 从左向右找第一个大于x的数
                 if($i < $j) 
                    $arr[$j--] = $arr[$i];
            }
            $arr[$i] = $x;
            if($i < $k-1){
                $this->quickSortTopic($arr, $i+1, $r, $k); /* 右区间递归调用 */
            }else{
                $this->quickSortTopic($arr, $l, $i-1, $k); /* 左区间递归调用 */
            }
        }
    }
}
```