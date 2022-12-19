### 解题思路
![image.png](https://pic.leetcode-cn.com/e6366baff746dea5ec3030b2bddba1b6440bcef2f6d6d4f9ba221d86407920ac-image.png)


### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function numberOfArithmeticSlices($A) {
        $total_arr_num = 0;//总共等差数组的子数组个数
        $last_diff_num = 0; //上一次循环匹配的数量个数
        $last_diff = null; //上一次循环匹配的差值
        foreach($A as $index => $item){
            if($index == 0){
                continue;
            }
            $diff = $item - $A[$index -1];
            if($last_diff === $diff){
                $last_diff_num += 1;
                $total_arr_num += $last_diff_num;
            }
            else{
                if($last_diff_num){
                    $last_diff_num = 0;
                }
                $last_diff = $diff;
            }
        }
        return $total_arr_num;
    }
}
```