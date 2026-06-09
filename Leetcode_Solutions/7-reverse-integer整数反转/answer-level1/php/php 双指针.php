### 解题思路
这种类型的题，基本上都可以用双指针去解

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        if($x == 0){
            return 0;
        } elseif($x > 0){
            $number = $x;
            $flag = 0;
        } else {
            $number = -$x;
            $flag = 1;
        }

        $len = strlen($number);
        $left = 0;
        $right = $len - 1;
        $number = strval($number);
        while($left < $right){
            $temp = $number[$left];
            $number[$left] = $number[$right];
            $number[$right] = $temp;
            $left += 1;
            $right -= 1;
        }

        $res =  $flag == 1 ? - intval($number) : intval($number);

        if($res >= 2147483647 or $res <= -2147483647){
            return 0;
        }

        return $res;

    }
}
```