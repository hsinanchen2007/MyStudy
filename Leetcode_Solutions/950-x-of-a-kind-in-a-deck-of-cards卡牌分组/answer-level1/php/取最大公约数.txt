### 解题思路
长话短说，就是一个判断最大公因数的题。先统计每张牌出现的次数(PHP自带 `array_count_values()` 函数)保存到新数组，然后计算新数组值的最大公约数。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $deck
     * @return Boolean
     */
    function hasGroupsSizeX($deck) {
        if (empty($deck)) {
            return false;
        }
        $counts = array_count_values($deck);
        $divisor = 0;
        foreach ($counts as $num) {
            $divisor = $this->ojld($num, $divisor);
            if ($divisor < 2) {
                return false;
            }
        }
        return true;
    }

    /**
    * 欧几里得算法取最大公约数
    * @param int $m 除数
    * @param int $n 被除数
    * @return int 返回两数最大公约数
    */
    public function ojld($m, $n) {
        while ($n != 0) {
            $r = $m % $n;
            $m = $n;
            $n = $r;
        }
        return $m;
    }
}

```