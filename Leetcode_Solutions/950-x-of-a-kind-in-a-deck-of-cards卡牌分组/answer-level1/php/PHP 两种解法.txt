### 解法一 按题意暴力解法
```php
class Solution
{
    function hasGroupsSizeX($deck)
    {
        $n = count($deck);
        if ($n <= 1) return false;
        sort($deck);
        for ($i = 2; $i <= $n; ++$i) {
            if ($n % $i == 0) {
                $groupCount = $n / $i;
                for ($j = 0; $j < $groupCount; ++$j) {
                    $g = array_slice($deck, $j * $i, $i);
                    if (array_sum($g) != end($g) * $i) {
                        continue 2;
                    }
                    if ($j == $groupCount - 1) return true;
                }
            }
        }
        return false;
    }
}
```


### 解法二 最大公约数解法

```php
class Solution {
    public function hasGroupsSizeX($deck)
    {
        $count = array_count_values($deck);
        // 迭代求多个数的最大公约数
        $x = 0;
        foreach ($count as $n) {
            $x = $this->gcd($x, $n);
            if ($x == 1) return false;
        }

        return $x >= 2;
    }

    private function gcd($a, $b)
    {
        return $b == 0 ? $a : $this->gcd($b, $a % $b);
    }
}
```