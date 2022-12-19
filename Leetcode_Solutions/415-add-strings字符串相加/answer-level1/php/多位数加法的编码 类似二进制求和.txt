### 解题思路
算数加法
### 代码

```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function addStrings($num1, $num2) {
        //第一部分 知道长短 短的补0 长短反转方便从头准备求和
        $strLongRev  = '';
        $strShortRev = '';
        $longLen = strlen($num1)>strlen($num2)?strlen($num1):strlen($num2);
        if ($longLen == strlen($num1)) {
            $strLongRev  = strrev($num1);
            $strShortRev = strrev($num2);
        }else {
            $strLongRev  = strrev($num2);
            $strShortRev = strrev($num1);
        }
        for ($i=0;$i<$longLen;$i++) {
            if($i>=strlen($strShortRev)) {
                $strShortRev .= '0';
            }
        } 
        // 第二部分 加法核心
        $nextAdd = 0;
        $current = '';
        for($i=0;$i<$longLen;$i++){
            $currentTemp = $strLongRev[$i] + $strShortRev[$i] + $nextAdd;
            $nextAdd = floor($currentTemp / 10);
            $current .= $currentTemp % 10;
        }
        // 必须要注意 遍历完需要看有没有进位
        if($nextAdd == 1){
            $current .= '1';
        }
        // 第三部分 反转得到结果
        return strrev($current);//注意反转  
            
    }
}
```