### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($x) {
        $rome = [
            1000 => "M",
            900  => "CM",
            500  => "D",
            400  => "CD",
            100  => "C",
            90   => "XC",
            50   => "L",
            40   => "XL",
            10   => "X",
            9    => "IX",
            5    => "V",
            4    => "IV",
            1    => "I",
        ];
        if (isset($rome[$x])){
            return $rome[$x];
        }
        $str = '';

        foreach ($rome as $key => $value) {
            if ($x < $key){
                continue;
            }
            $multi = floor($x / $key);
            if ($multi > 0 ){
                $x = $x - $key * $multi;
                $str .= str_pad($rome[$key],$multi,$rome[$key]);
            }
        }

        return $str;
    }
}
```