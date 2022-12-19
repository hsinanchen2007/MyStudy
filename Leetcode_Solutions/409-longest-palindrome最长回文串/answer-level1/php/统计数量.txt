### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $len=strlen($s);
        if($len<=1){
            return $len;
        }
        $count=0;
        $one=0;
        $arrCount=array_count_values(str_split($s));
        foreach($arrCount as $num){
            if($num%2==1){
                $one=1;
            }
            $count+=$num%2==1?$num-1:$num;
        }
        return $count+$one;
        
    }
}
```