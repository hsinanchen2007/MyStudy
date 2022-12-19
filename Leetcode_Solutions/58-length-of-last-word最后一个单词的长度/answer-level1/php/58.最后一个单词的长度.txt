### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
        $len = strlen($s);
        if($len === 0){
            return 0;
        }
        if($s[$len-1] === ' '){
            if($len === 1){
                return 0;
            }
            $s = substr($s,0,$len-1);
            return $this->lengthOfLastWord($s);
        }else{
            $i = $len - 1;
            while($i >= 0){
                if($s[$i] === ' '){
                    return $len - 1 - $i;
                }
                $i--;
            }
            if($len > 0){
                return $len;
            }
        }
    }
}
```