### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function tribonacci($n) {
        $fn = [0=>0,1=>1,2 =>1];
        for ($i= 3; $i <= $n; $i++) {
            $fn[$i] = $fn[$i- 1] + $fn[$i- 2] + $fn[$i - 3];            
        }
        if($fn[$n] > (pow(2,31) -1)) return pow(2,31) -1;
        return $fn[$n];
    }
}
```