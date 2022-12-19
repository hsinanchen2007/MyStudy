### 解题思路
1, 本来是通过pow()函数判断结果是否溢出,偶然看到1<<31居然可以表示最大(小)值
2, 1<<31-1 == 1<<(31-1) 即:算术运算符的优先级大于位运算符

关于1<<31,在有的平台它表示负数,也有部分平台表示正数!
### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        if($x==0) return $x;
        $x = strrev(abs($x))*$x/abs($x);
        if($x>(1<<31)-1 || $x<-1<<31) return 0;
        return $x;
    }
}
```