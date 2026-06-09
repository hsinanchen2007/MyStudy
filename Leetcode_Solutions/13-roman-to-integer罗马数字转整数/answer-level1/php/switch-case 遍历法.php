执行用时 :
24 ms
, 在所有 PHP 提交中击败了
82.27%
的用户
内存消耗 :
14.7 MB
, 在所有 PHP 提交中击败了
48.63%
的用户

switch-case 遍历法*/

```
class Solution {

    /*switch-case 遍历法*/
    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $res = 0;
        $n = strlen($s);
        for($i=0;$i<$n;$i++){
            switch($s[$i])
            {
                case 'I':
                    if($i<$n-1 && $s[$i+1]=='V')
                    {
                        $res += 4;
                        $i++;
                    }else if($i<$n-1 && $s[$i+1]=='X'){
                        $res += 9;
                        $i++;
                    }
                    else $res++;
                    break;
                case 'V':
                    $res += 5;
                    break;
                case 'X':
                    if($i<$n-1 && $s[$i+1]=='L')
                    {
                        $res += 40;
                        $i++;
                    }else if($i<$n-1&&$s[$i+1]=='C'){
                        $res += 90;
                        $i++;
                    }
                    else $res+=10;
                    break;
                case 'L':
                    $res += 50;
                    break;
                case 'C':
                    if($i<$n-1 && $s[$i+1]=='D')
                    {
                        $res += 400;
                        $i++;
                    }else if($i<$n-1 && $s[$i+1]=='M'){
                        $res += 900;
                        $i++;
                    }else{
                        $res += 100;
                    }
                    break;
                case 'D':
                    $res += 500;
                    break;
                case 'M':
                    $res += 1000;
            }
        }
        return $res;
        
    }
}
```
