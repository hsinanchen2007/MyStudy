### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $res = 0;
        for($i=0;$i<strlen($s);$i++){
            if($s[$i] == 'I'){
                if($i<strlen($s)-1 && $s[$i+1] == 'V'){
                    $res += 4;
                    $i++;
                }
                elseif($i<strlen($s)-1 && $s[$i+1] == 'X'){
                    $res += 9;
                    $i++;
                }
                else{
                    $res += 1;
                }
            }
            elseif($s[$i] == 'V'){
                $res += 5;
            }
            elseif($s[$i] == 'X'){
                if($i<strlen($s)-1 && $s[$i+1] == 'L'){
                    $res += 40;
                    $i++;
                }
                elseif($i<strlen($s)-1 && $s[$i+1] == 'C'){
                    $res += 90;
                    $i++;
                }else{
                    $res += 10;
                }
            }
            elseif($s[$i] == 'L'){
                $res += 50;
            }
            elseif($s[$i] == 'C'){
                if($i<strlen($s)-1 && $s[$i+1] == 'D'){
                    $res += 400;
                    $i++;
                }
                elseif($i<strlen($s)-1 && $s[$i+1] == 'M'){
                    $res += 900;
                    $i++;
                }else{
                    $res += 100;
                }
            }
            elseif($s[$i] == 'D'){
                $res += 500;
            }
            else{
                $res += 1000;
            }
        }
        return $res;
    }
}
```