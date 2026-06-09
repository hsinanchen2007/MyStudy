### 解题思路
双指针法，这样可以把空间复杂度降到最低。

i指向数组最左边，j指向数组最右边

### 代码

```php
class Solution {
    function exchange($nums){
        $i=0;
        $j=count($nums)-1;
        while($i<$j){
            //一直走，直到遇到偶数(否则不停下来))
            if($nums[$i]%2!=0){
                $i++;
                continue;
            }

            //一直走，直到遇到奇数(否则不停下来))
            if($nums[$j]%2==0){
                $j--;
                continue;
            }

            //奇数偶数交换
            $tmp = $nums[$i];
            $nums[$i] = $nums[$j];
            $nums[$j] = $tmp;
        }
        return $nums;
    }
}
```