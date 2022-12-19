### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        if($n<=1){
            return $n;
        }
        $one=0;
        $two=1;
        $three=1;
        for($i=2;$i<=$n;$i++){
            $three=($one+$two)%1000000007;
            $one=$two;
            $two=$three;
        }
        return $two;
    }
}
```