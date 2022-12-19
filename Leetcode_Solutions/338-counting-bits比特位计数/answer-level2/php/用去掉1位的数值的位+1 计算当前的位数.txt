### 解题思路
要获取当前节点的1的个数，首先获取去掉1位1之后的节点的个数 + 1 。 理解这一点非常重要。 
我们用bits 存放当前数字对应的位数，当然节点去掉1位后变成 $i & ($i -1) 值， 然后去bits 里获取已经计算的结果。 

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer[]
     */
    function countBits($num) {
        $bits[0] = 0 ;
        for($i = 1; $i <= $num; $i++){
            $bits[$i] = $bits[$i & ($i -1)] + 1;
        }
        return $bits;
    }
}
```