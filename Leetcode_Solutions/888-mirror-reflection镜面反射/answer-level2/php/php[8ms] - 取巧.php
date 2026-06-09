### 解题思路
![image.png](https://pic.leetcode-cn.com/82425b2d11c3f63df0ee94a2fba79cbe165601f6f6b8e1dfb6d4d2d0f7ecbe6f-image.png)

根据光线在东西方向和南北方向的行走距离，应该成一个整数比，求得最小满足的公倍数k，然后判断k的奇偶可得在东西哪个点，以及在南北方向走的奇偶可得在南北哪个点。

### 代码

```php
class Solution {

    /**
     * @param Integer $p
     * @param Integer $q
     * @return Integer
     */
    function mirrorReflection($p, $q) {
        if($q == 0) return 0;
        if ($p == $q) return 1;

        $k = 0; //光线在正方形内东西方向所经历的步数

        //取巧，题目给出范围，求出最小的$k，使得满足($k * $q) % $p == 0
        for($i = 1; $i <= 1000; $i++){
            if((($i * $q) % $p) == 0){
                $k = $i;
                break;
            }
        }
        //奇数，判断南北
        if($k % 2){
            if((($k * $q) / $p) % 2){
                return 1;
            }
            return 0;
        }
        //偶数，在左边，只有2
        return 2;
    }
}
```