### 解题思路
将数字转换成数组，并翻转数组，再将数组中最前面的0删去，判断原数字是否大于零，决定是否添加负号。最后判断新数字的绝对值是否大于2^31.

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        if ($x == 0) {
            return '0';
        }
        $xx = abs($x);
        $xarray = str_split($xx);
        for ($i = count($xarray)-2; $i >= 0; $i--) {
            $tem = $xarray[$i];
            unset($xarray[$i]);
            array_push($xarray, $tem);
        }
        $xarray = array_values($xarray);
        while ($xarray[0] == '0') {
            unset($xarray[0]);
            $xarray = array_values($xarray);
        }
        if ($x>0) {
            $x = implode($xarray);
        }else{
            $x = -implode($xarray);
        }
        if (abs($x)>pow(2,31)) {
            return '0';
        }else{
            return $x;
        }
    }
}
```