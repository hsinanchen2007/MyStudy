### 解题思路
判断当前的数 是否大于0  ? 去当前这个数的正整数，过滤掉后尾的0 ：反转当前数

判断获取到的当前数是否符合区间
### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        if ($x>0) {
            $dat = abs(strrev($x));
         }else{
            $dat = -strrev($x);
         }
         
         if ($dat< pow(-2,31) || $dat> (pow(2,31)-1)) {
             $dat = 0;
         }
         return $dat;
    }
}
```