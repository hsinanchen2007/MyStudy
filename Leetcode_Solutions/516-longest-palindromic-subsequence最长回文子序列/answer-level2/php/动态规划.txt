### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindromeSubseq($s) {
        if(empty($s)){
            return 0;
        }
        $length=strlen($s);
        $dp=[];
        for ($c = 0; $c < $length; $c++) {
            for ($v = 0; $v < $length; $v++) {
                if ($c == $v) {
                    $dp[$c][$v] = 1;
                } else {
                    $dp[$c][$v] = 0;
                }
            }
        }
        //反着遍历

        for($i=$length-1;$i>=0;$i--){
            for($j=$i+1;$j<$length;$j++){
                if($s[$i]==$s[$j]){
                    $dp[$i][$j]=$dp[$i+1][$j-1]+2;
                }else{
                    $dp[$i][$j]=max($dp[$i+1][$j],$dp[$i][$j-1]);
                }
            }
        }
        return $dp[0][$length-1];
        
    }
}
```