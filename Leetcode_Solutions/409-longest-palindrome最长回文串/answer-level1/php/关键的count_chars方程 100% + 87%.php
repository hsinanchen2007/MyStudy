### 解题思路
找出每个字符出现次数，偶数全加，奇数减一加，最后奇数减一加出现至少一次的话，最后结果再加以，作为中位数

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $arr = count_chars($s, 1);//所有字符出现次数
        $center_single_digit = 0;//中位数
        $lp = 0;
        foreach($arr as $char => $char_count){
            if($char_count%2==0) $lp += $char_count;
            else{
                $lp += $char_count-1;
                $found_center_single_digit = 1;
            }
        }

        return $lp + $found_center_single_digit;
    }
}
```