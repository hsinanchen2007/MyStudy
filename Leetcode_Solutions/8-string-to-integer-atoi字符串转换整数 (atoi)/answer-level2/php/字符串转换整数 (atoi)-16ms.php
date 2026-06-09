### 解题思路
按部就班的一个个添加限制条件

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        $str = ltrim($str);
        $stra = str_split($str);
        $i = 0;
        while ($i<count($stra)) {
            if (preg_match ("/^[a-z]/", $stra[$i])) {
                $stra = array_slice($stra,0,$i);
                break;
            }
            $i++;
        }
        if (count($stra) == 0) {
            return 0;
        }else {
            $str = implode($stra);
            if ($str>=pow(2, 31)) {
                return pow(2, 31)-1;
            }elseif($str< -pow(2, 31)){
                return -pow(2, 31);
            }
            return intval($str);
        }
    }
}
```