### 解题思路
加入一个dp表即可

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */

    function fib($n) {
        // //basic
        // if($n<2) return $n;
        // return $this->fib($n-1) + $this->fib($n-2);

        if($n<2) return $n;
        $dp = [];
        $dp[0] = 0;
        $dp[1] = 1;

        for($i=2;$i<=$n;$i++){
            $dp[$i] = ($dp[$i-1] + $dp[$i-2])%1000000007;
        }

        return $dp[$n];

    }

}
```