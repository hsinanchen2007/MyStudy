```php
class Solution {

    /**
     * @param Integer[] $deck
     * @return Boolean
     */
    function hasGroupsSizeX($deck) {
        $map = array_count_values($deck);
        $g = -1;
        foreach($map as $i=>$count) {
            $g = $g == -1 ? $count : $this->gcd($g, $count);
        }
        return $g >= 2;
    }
    function gcd ($x , $y) {
        return $y == 0 ? $x : $this->gcd($y, $x % $y);
    }
}
```
