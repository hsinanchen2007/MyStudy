### 解题思路
题目可转化为求一个数的因数个数，个数为奇数的最后才可以保持亮的状态。

只有完全平方数的因数个数为奇数个。

求 1-n 范围内完全平方数的个数即可。

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function bulbSwitch($n) {
        return floor(sqrt($n));
    }
}
```