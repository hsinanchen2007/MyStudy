### 解题思路

看了下各位大神的解题思路，感觉都很棒，这里提出一个新的解题思路，不是最好的，但也是一种方法。

先根据滑动窗口思想，找出连续X个能惹生气的最大客户数量的数组下标，然后再替换原有的grumpy数组，改1为0，最后再输出

![image.png](https://pic.leetcode-cn.com/6f830bca3e7492bd02bd51427087f864cdcaf494a2590901d9cb490a45e68b0e-image.png)

### 代码

```php
class Solution {

    /**
    * @param Integer[] $customers
    * @param Integer[] $grumpy
    * @param Integer $X
    * @return Integer
    */
    function maxSatisfied($customers, $grumpy, $X) {
        $max_grumpy = 0; //最大能惹生气的客户数量
        $max_grumpy_index = 0; //最大惹生气的客户数量的开始索引
        $last_grumpy = 0; //上一次循环惹生气的客户数量
        $last_grumpy_index = 0; //上一次循环开始的索引

        foreach($customers as $index => $customer){
            if($index < $X){
                $max_grumpy += $customer;
                $last_grumpy = $max_grumpy;
            }
            if($index >= $X){
                $this_grumpy = $last_grumpy;
                //减去头
                if($grumpy[$index - $X]){
                    $this_grumpy -= $customers[$index - $X];
                }
                //加上尾
                if($grumpy[$index]){
                    $this_grumpy += $customers[$index];
                }
                //当前循环
                $last_grumpy = $this_grumpy;
                $last_grumpy_index = $index - $X + 1;

                //比较大小,进行替换
                if($this_grumpy > $max_grumpy){
                    $max_grumpy = $this_grumpy;
                    $max_grumpy_index = $index - $X + 1;
                }
            }
        }

        $reset_grumpy = $grumpy;
        for ($i=0; $i < $X; $i++) {
            $reset_grumpy[$max_grumpy_index + $i] = 0;
        }

        $well_customer_num = 0; //最多有多少客户能够感到满意的数量
        foreach($customers as $index => $customer){
            if(!$reset_grumpy[$index]){
                $well_customer_num += $customer;
            }
        }
        return $well_customer_num;
    }
}
```