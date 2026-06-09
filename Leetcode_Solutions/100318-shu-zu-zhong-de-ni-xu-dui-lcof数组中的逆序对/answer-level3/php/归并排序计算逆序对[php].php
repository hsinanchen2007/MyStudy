### 解题思路
见代码

### 代码

```php
class Solution {

   //出现逆序对的个数
    private $cnt=0;

    function reversePairs($nums){
        $this->merge_sort_helper($nums,0,count($nums)-1);
        return $this->cnt;
    }

    //分治
    function merge_sort_helper(&$nums,$l,$r){
        if($l>=$r) return;
        $mid = intval(floor(($l+$r)/2));
        $this->merge_sort_helper($nums,$l,$mid);
        $this->merge_sort_helper($nums,$mid+1,$r);
        $this->merge($nums,$l,$mid,$r);
    }

    //合并
    function merge(&$nums,$l,$mid,$r){
        $i = $l;     // 左数组的下标
        $j = $mid + 1;  // 右数组的下标
        $temp = [];// 临时合并数组
        while($i<=$mid && $j<=$r){
            if($nums[$i]<=$nums[$j]){
                $temp[] = $nums[$i];
                $i++;
            }else{
                //如果左边部分的数字大于右边的数字
                $this->cnt += $mid-$i+1;
                $temp[] = $nums[$j];
                $j++;
            }
        }

        while ($i <= $mid) {
            $temp[] = $nums[$i];
            $i++;
        }
        while ($j <= $r) {
            $temp[] = $nums[$j];
            $j++;
        }
        for($k = 0; $k < count($temp); $k++) {
            $nums[$l + $k] = $temp[$k];
        }
    }
}
```