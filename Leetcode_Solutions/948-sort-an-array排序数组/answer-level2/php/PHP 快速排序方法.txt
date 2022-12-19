### 解题思路
快速排序也是分治思想，选取待排序数组一分区点，分别从数组两端进行排序，从右边开始遍历，如果数值比分区点大，循环继续向前走，如果比分区点数小的放左边，从右向左的循环停止， 开始从左边向右遍历，如果待排序数值小于分区点，循环继续向右走， 如果大于分区点，将当前值赋值给top，当前循环停止。
关键点： 递归循环结束条件 low < top 
每次排序循环时， 如果发生赋值就停止当前循环，从相反方向继续循环。 
一次排序结束后，将分区点的值赋值给 data[low] 
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortArray($nums) {
        $length = count($nums);
        return $this->quickSort($nums, 0, $length-1);
    }
    
    function quickSort(&$data, $low, $top)
    {
        if($low < $top){
            $pivot = $this->partition($data, $low, $top);
            $this->quickSort($data, $low, $pivot-1);
            $this->quickSort($data, $pivot + 1, $top);
        }
        return $data;
    }
    function partition(&$data, $low, $top)
    {
        if($low == $top){
            return;
        }
        $compare = $data[$low];
        while($low != $top)
        {
            while($top && $top!=$low){
                if($compare > $data[$top]){
                    $data[$low++] = $data[$top];
                    break;
                }else{
                    $top--;
                }
            }

            while($low && $low!=$top){
                if($data[$low] > $compare){
                    $data[$top--] = $data[$low];
                    break;
                }else{
                    $low++;
                }
            }
        }
        $data[$low] = $compare;
        return $low;
    }
}
```