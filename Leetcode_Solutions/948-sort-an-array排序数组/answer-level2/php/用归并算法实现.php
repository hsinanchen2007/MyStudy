### 解题思路
归并排序使用的思想就是递归，将待排序数组分为前后两部分，分别将前后两部分进行排序，再将两有序数组合并。
注意递归的终止条件是，如果只剩下一个元素的时候直接返回当前元素所在数组。
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortArray($nums) {
        $length = count($nums);
        if ($length <= 1){
            return $nums;
        }
        return $this->mergeRecursive($nums, 0, $length-1);
    }
    
    function mergeRecursive($data, $start, $end)
    {
        //终止条件
        if ($start >= $end){
            return [$data[$start]];
        }
        //递归公式
        $mid = (int) (($start + $end) / 2);
        $left = $this->mergeRecursive($data, $start, $mid);
        $right = $this->mergeRecursive($data, $mid + 1, $end);
        return $this->merge($left, $right);
    }

    function merge($left, $right)
    {
        $leftLength = count($left);
        $rightLegth = count($right);
        $i = 0;
        $j = 0;
        $tmp = [];
        while ($i < $leftLength && $j < $rightLegth){
            if ($left[$i] <= $right[$j]){
                $tmp[] = $left[$i++];
            }else{
                $tmp[] = $right[$j++];
            }
        }
    
        $start = $i;
        $copyArr = $left;
        $end = $leftLength;
    
        if ($j < $rightLegth){
            $start = $j; $end = $rightLegth; $copyArr = $right;
        }
        while ($start < $end){
            $tmp[] = $copyArr[$start++];
        }
        return $tmp;
    }
}
```