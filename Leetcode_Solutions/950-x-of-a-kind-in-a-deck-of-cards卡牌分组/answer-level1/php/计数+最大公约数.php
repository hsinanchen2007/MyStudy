### 解题思路
官方解，计算每个数字出现的次数之后看看有没有大于1的公约数

### 代码

```php
class Solution {

    /**
     * @param Integer[] $deck
     * @return Boolean
     */
    function hasGroupsSizeX($deck) {
        if(count($deck) < 2) return false;
        $values_count = array_count_values($deck);
  
        $x = 0;
        foreach($values_count as $value){
            $x = $this->gcd($x, $value); //重复计算最大公约数
            if ($x == 1) { // 如果某步中最大公约数是1则返回
                return false;
            }
        }
        return true;;
    }

    private function gcd($a, $b) {
        if ($b == 0) {
            return $a;
        }
        return $this->gcd($b, $a % $b);
    }
}
```