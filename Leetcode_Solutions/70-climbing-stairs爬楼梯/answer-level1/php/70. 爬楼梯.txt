### 解题思路
1. 斐波那契数列
2. 计算第n项数据（第n-1项 + n-2项之和）

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function climbStairs($n) {
        $ans['0'] = 1;
        $ans['1'] = 1;
        for($i=2; $i<=$n; $i++){
            $ans[$i] = $ans[$i-1] + $ans[$i-2];
        }
        return $ans[$n];
    }
}
```