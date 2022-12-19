### 解题思路
1、处理字符串，将字符串中的非字母和非数字删除并全部转换成小写
2、将字符串转换成数组，根据数组的长度的奇偶性分别给出不同的判定方式
有点麻烦，后面进一步改进

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) {
        if ($s == '' ) {
            return true;
        }
        $s = str_replace(' ','',$s);
        $s = strtolower(preg_replace('/[^a-z0-9 ]/i','',$s));
        $ss = str_split($s);
        for ($i = 0; $i < count($ss); $i++) {
            if ( !preg_match ("/^[a-z]/", $ss[$i]) && !preg_match ("/^\d*$/", $ss[$i])) {
                unset($ss[$i]);
            }
        }
        if (count($ss) == 1) {
            return true;
        }
        $ss = array_merge($ss);        
        $num = $st = $j = 0;
        if (count($ss)%2 != 0) {
            $num = (count($ss)-1)/2;
            while ($j <= $num) {
                if ($ss[$num+$j] == $ss[$num-$j]) {
                    $st++;
                }
                $j++;
            }
            if ($st == $num+1) {
                return true;
            }
        }else{
            $j = 1;
            $num = count($ss)/2;
            while ($j <= $num) {
                if ($ss[$num-$j] == $ss[$num+($j-1)]) {
                    $st++;
                }
                $j++;
            }
            if ($st == $num) {
                return true;
            }
        }
        return false;
    }
}
```