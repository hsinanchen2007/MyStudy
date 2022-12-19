### 解题思路
计算出质数的全排列数和非质数的全排列数，然后相乘即可。记得要模一下，否则会溢出

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function numPrimeArrangements($n)
    {
        $primeNums   = $this->primeCount($n);
        $noPrimeNums = $n - $primeNums;
        $res         = 1;
        $this->factorial($res, $primeNums);
        $this->factorial($res, $noPrimeNums);
        return $res;
    }

    function primeCount($n)
    {
        $isPrim = [];
        for ($i = 2; $i <= $n; $i++) {
            $isPrim[$i] = true;
        }
        for ($i = 2; $i * $i <= $n; $i++) {
            if ($isPrim[$i]) {
                for ($j = $i * $i; $j <= $n; $j += $i) {
                    $isPrim[$j] = false;
                }
            }
        }
        return array_sum($isPrim);
    }

    function factorial(&$res, $nums)
    {
        $mod = 1000000007;
        for ($i = 2; $i <= $nums; $i++) {
            $res = ($res * $i) % $mod;
        }
    }
}
```