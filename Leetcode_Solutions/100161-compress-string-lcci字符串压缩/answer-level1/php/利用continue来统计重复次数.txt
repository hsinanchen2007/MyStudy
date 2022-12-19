### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function compressString($S) {
        $len = strlen($S);
        if ($len < 1) {
            return "";
        }
        $count = 1;
        for($i = 0; $i < $len; $i++) {
            if($S[$i] == $S[$i+1]) {
                $count++;
                continue;
            }
            $newStr .= $S[$i].$count;
            $count = 1;
        }
        $newLen = strlen($newStr);
        if ($newLen >= $len) {
            $newStr = $S; 
        }
        return $newStr;
    }
}
```