### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function minSubsequence($nums) {
        rsort($nums);
        $num = 0;
        $sum = array_sum($nums);
        $arr = [];
       foreach($nums as $key=> $v)
       {
           if($sum-$num>=$num)
           {
               $arr[] = $v;
               $num+=$v;
           }
       }

       return $arr;  
    }
}
```