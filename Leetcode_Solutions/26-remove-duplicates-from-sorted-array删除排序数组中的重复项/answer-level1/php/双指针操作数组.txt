### 解题思路
此处撰写解题思路
双下标操作数组，两个下标的起点都是1，因为数组最少也要返回一个数，然后循环遍历数组，用第一个下标跟第二个下标的前一个元素比较，如果不相等就用户第一个下标给第二个下标赋值，如果数组中完全没有重复项，那么两个下标的步伐应该是一样的，一旦有重复项那么第一个下标就会比第二个下标走的快，最终返回第二个下标的值

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        if(empty($nums)){
            return 0;
        }
        $l = count($nums);
        $k = 1;
        for($i = 1; $i < $l; $i++){
            if($nums[$i] > $nums[$k-1]){
                $nums[$k] = $nums[$i];
                $k++;
            }
        }
        return $k;
    }
}
```