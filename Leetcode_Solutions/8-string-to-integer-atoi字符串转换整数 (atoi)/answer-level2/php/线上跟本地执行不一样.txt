### 解题思路
此处撰写解题思路
我本地不用把e换成特殊字符，线上直接把科学计数法解析开来了，所以这里特别把e换成#来强制避免这个干扰
### 代码

```php
class Solution
{

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str)
    {
        $str = str_replace('e','#',$str);
        $str = trim($str);
        $i = intval($str);
        $max = pow(2, 31) - 1;
        $min = pow(-2, 31);
        if ($i < $min) {
            $i = $min;
        }
        if ($i > $max) {
            $i = $max;
        }
        return $i;
    }
}
```