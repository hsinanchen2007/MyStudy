### 解题思路
贪心

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $roman = '';
        $nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        $romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

        $index = 0;
        while($index < 13){
            if($num >= $nums[$index]){
                $roman .= $romans[$index];
                $num -= $nums[$index];
            }else{
                $index++;
            }
        }
        
        return $roman;
    }
}
```