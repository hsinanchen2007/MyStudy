
字符串方式：

![image.png](https://pic.leetcode-cn.com/12350bc1b0882b0f1e3270d68bc3d4df318027a7f68dc301261727f74231ff1e-image.png)


```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function maximum69Number ($num) {
        $numString = (string)$num;
        if( ($pos = strpos($num,'6')) !== false){
            $numString[$pos]='9';
        };
        return (int)$numString;
    }
}
```


除法方式

![image.png](https://pic.leetcode-cn.com/57bd3bcf3bcc9b05e3cac001f47eadce58b082b89e043c79187d2ceb3255c79a-image.png)


```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function maximum69Number ($num) {
        $len = (int)ceil(log10($num));
        $numorg = $num;
        for ($i=$len;$i>=1;$i--){
            $cur = (int)($num / pow(10,$i-1));
            $curMax = $cur * pow(10,$i-1);
            if($cur != 9){
                return $numorg - $curMax+ 9 * pow(10,$i-1);
            }
            $num -= $curMax;

        }
        return $numorg;
    }
}
```

