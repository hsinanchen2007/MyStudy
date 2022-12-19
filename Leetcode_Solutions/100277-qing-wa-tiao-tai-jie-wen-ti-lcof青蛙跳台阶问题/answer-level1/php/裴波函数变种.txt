### 解题思路
数学思路-总结规律
$f(0) = 1;
$f(1) = 1;
$f(2) = 2;
...
$f(n) = $f(n-1) + $f(n-2);(n > 1)



### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function numWays($n) {
        if($n == 0) return 1;
        if  ($n <= 2) return $n;
        $pre = 1;
        $cur = 2;
        for($i=3;$i<=$n;$i++){
            $res = ($pre+$cur)%(1e9+7);
            $pre = $cur;
            $cur = $res;
        }
        return $res;
    }
}
```