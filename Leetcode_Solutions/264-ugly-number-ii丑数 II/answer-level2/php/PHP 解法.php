### 解题思路


### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function nthUglyNumber($n) {
        // 三指针 + dp
        // $dp[] 存储所有找到丑数
        // 三个指针，存储下标
        $dp = [1];
        $index2 = $index3 = $index5 = 0;
        for ($i = 0; $i < $n - 1; ++$i) {
            $min = min($dp[$index2] * 2, $dp[$index3] * 3, $dp[$index5] * 5);
            if ($min == $dp[$index2] * 2) {
                $index2++;
            }
            if ($min == $dp[$index3] * 3) {
                $index3++;
            }
            if ($min == $dp[$index5] * 5) {
                $index5++;
            }
            $dp[] = $min;
        }

        return $dp[$n - 1];
    }
}
```