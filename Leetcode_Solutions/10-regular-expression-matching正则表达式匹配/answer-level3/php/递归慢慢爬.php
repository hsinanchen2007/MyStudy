### 解题思路
感谢[@andfly](/u/andfly/)的解答，磨蹭了一个小时终于搞懂了，Recursive方程真的有点烧脑🤯

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $p
     * @return Boolean
     */
    function isMatch($s, $p) {

        if(empty($p)) {
            //echo "EMPTY! \n";
            return empty($s);
        }

        $first_char_match = !empty($s) && ($p[0]==$s[0] || $p[0]=='.');
    
        if(strlen($p)>=2 && $p[1]=='*'){
            //echo "1st match $s " . substr($p,2) . "\n";
            //$second_char_match = $this->isMatch($s, substr($p,2));
            //echo "2nd match " . substr($s,1) . " $p \n";
            //$rest_char_match = $first_char_match && $this->isMatch(substr($s,1), $p);
            //return $second_char_match || $rest_char_match;
            return $this->isMatch($s, substr($p,2)) || ($first_char_match && $this->isMatch(substr($s,1), $p));
        }
        else{
            //echo "3rd match " . substr($s,1) . " " . substr($p,1) ." \n";
            return $first_char_match && $this->isMatch(substr($s,1), substr($p,1));
        }

    }
}
```