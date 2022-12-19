### 解题思路
见代码

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $n
     * @return String
     */
    function reverseLeftWords($s, $n) {
        if(empty($s) || $n==0) return $s;
        $sub_str="";
        for($i=0;$i<$n;$i++){
            $sub_str.=$s[$i];
        }
        $s .= $sub_str;
        $n_s = "";
        for($i=$n;$i<strlen($s);$i++){
            $n_s.=$s[$i];
        }
        return $n_s;
    }
}
```