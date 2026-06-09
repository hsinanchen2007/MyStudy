### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        $l1 = strlen($haystack);
        $l2 = strlen($needle);
        if($l2 == 0){
            return 0;
        }
        for($i=0;$i<$l1;$i++){
            if($haystack[$i] == $needle[0] && $l1 - $i >= $l2){
                for($j=0;$j<$l2;$j++){
                    if($haystack[$i+$j] != $needle[$j]){
                        break;
                    }elseif($j == $l2-1){
                        return $i;
                    }
                }
            }
        }
        return -1;
    }
}
```