### 解题思路


### 代码

```php
class Solution {

    /**
     * @param Integer[] $deck
     * @return Boolean
     */
    function hasGroupsSizeX($deck) {
        if(!isset($deck[1])){
           return false;
       }
       $count = array_count_values($deck);
       unset($deck);
       //$count = array_unique($count);
       $x = array_shift($count);
       foreach($count as $v){
           $x = $this->gcd($x, $v);
           if( $x == 1) {
               return false;
           }
       }
       return true;
    }

    function gcd($a, $b) {
        return $b == 0 ? $a : $this->gcd($b, $a%$b);
    }
}
```