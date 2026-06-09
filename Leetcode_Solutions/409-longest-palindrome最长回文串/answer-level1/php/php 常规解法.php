### 解题思路

*将字符串做成key为字符串，value为该字符串出现次数的数组
*将次数相加，在相加的过程中，遇到奇数次，则-1
*如果出现过一次奇数次，则将改奇数次当成对称中心，标记，最后+1

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $len = strlen($s);
        $rept = [];
        for($i = 0; $i < $len; $i++){ 
            if(isset($rept[$s[$i]])){
                $rept[$s[$i]] += 1;
            } else {
                $rept[$s[$i]] = 1;
            }
        }
        $sum = 0;
        $flag = 0;
        foreach($rept as $v){
            // 奇数
            if($v % 2){
                $flag = 1;
                $sum += $v - 1;
            } else {
                $sum += $v;
            }
        }

        return $flag == 1 ? $sum + 1 : $sum;
    }
}
```