### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function addStrings($num1, $num2) {
        $count1=strlen($num1);
        $count2=strlen($num2);
        $i=$count1-1;
        $j=$count2-1;
        $carry=0;
        $res='';
        while($i>=0  || $j>=0){
            $n1=($i>=0)?$num1[$i]:0;
            $n2=($j>=0)?$num2[$j]:0;
            $sum=$n1+$n2; 
        
            $temp = $sum + $carry;
            $carry = (int)($temp / 10);
            $res = ($temp % 10) . "" . $res;
            $i--;
            $j--;
        }
        if ($carry == 1) {
            $res = $carry . "" . $res;
        }
        return $res;
    }
}
```