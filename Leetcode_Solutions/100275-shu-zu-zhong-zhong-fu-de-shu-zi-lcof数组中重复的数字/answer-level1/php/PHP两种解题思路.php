## 1、类似于桶排序
有点类似于桶排序，使用一个数组，如果发现该桶数量＞1，则该桶就是重复数字。

时间复杂度是O(n)，由于需要开辟新空间，空间复杂度也是O(n)
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findRepeatNumber($nums) {
        $new_nums = [];
        foreach($nums as $num){
            if(isset($new_nums[$num])){
                return $num;
            }
            $new_nums[$num]=1;
        }
        return ;
    }
}
```

## 2、位置交换，重排数组

因为有while循环，但直到循环完数组也找不到重复数字的概率很小，所以均摊时间复杂度是O(n)，空间复杂度是O(1)
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findRepeatNumber($nums) {
        foreach($nums as $k=>$num){
            while($nums[$k] != $k){
               if($nums[$k] == $nums[$nums[$k]]){
                   return $nums[$k];
               }
               $temp = $nums[$k];
               $nums[$k] = $nums[$temp];
               $nums[$temp] = $temp;
            }
        }
        return ;
    }
}
```
这种解法的思路就是利用了长度为n的数组，数值范围是[0,n-1)。这样的话，利用交换将 $nums[i] == i。
交换的过程中，很大概率会出现重复数字。