![A06E0C5F592D98F52413427E0C5F6D76.jpg](https://pic.leetcode-cn.com/7c2539825551dfe9e22e3d80906a7a5603e7dd05b60937f2e048cf2ef00cc95f-A06E0C5F592D98F52413427E0C5F6D76.jpg)

```
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $result = '';
        $x = (string)$x;
        if($x[0] == '-') {
            for($i=strlen($x)-1;$i>0;$i--) {
                $result += ((int)$x[$i]) * pow(10,$i-1);
            }
            $result = 0-$result;
        }else{
            for($i=strlen($x)-1;$i>=0;$i--) {
                $result += ((int)$x[$i]) * pow(10,$i);
            }
        }
        if($result < pow(-2,31) || $result > pow(2,31) - 1) return 0;
        return $result;
    }
}
```

最原始的方法做出来的，但是想看看大家有没有更好的方法