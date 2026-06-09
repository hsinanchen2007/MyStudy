规律1： 当 n = 1 时，存在 f(n) = 1, b(n) = 1
规律2： 对于任意 n，存在 f(n) + b(n) = n + 1
规律3： 对于 n > 2 的情况下，f(n) = 2 * b(n / 2)
解题公式：f(n) = 2 * b(n / 2) = 2 * (n / 2 + 1 - f(n / 2))
```
function lastRemaining($n) {
    return $n==1?1:2*(floor($n/2)+1-$this->lastRemaining(floor($n/2)));
}
```
