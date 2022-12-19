### 解题思路
最开始是想用二进制，然后循环加判断来完成的。
转换为二进制后，发现**位运算**步骤可以转换为**计算字符串长度**
>因为每次左移就会减少一位，直到剩下一位
>>最高位一定为1，这就是为什么要-1

而判断**是否为奇数**，可以换成计算二进制字符串中 **1 出现的次数**
>因为每次位运算后，遇到1就需要-1，相当于多操作一步后再位维算

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function numberOfSteps ($num) {
        $bin = decbin($num);//转换为二进制
        return strlen($bin) + substr_count($bin,1) -1;//计算二进制字符串长度，1的位数，最后-1
    }

}
```