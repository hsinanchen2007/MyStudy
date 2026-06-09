### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function numSquares($n) {
        //下标0-n+1的数组，值为0
        $dp = array_fill(0, $n + 1, 0);
        for ($i = 1; $i <= $n; $i++) {
            $dp[$i] = $i;//最大个数为i,表示全部为1
            for ($j = 1; $i - $j * $j >= 0; $j++) {
                //重点是下面的动态转移公式，$dp[$i - $j * $j]为已经计算好的最小值，后面再加1 
                $dp[$i] = min($dp[$i], $dp[$i - $j * $j] + 1);
            }
        }

        return $dp[$n];
    }
}
```