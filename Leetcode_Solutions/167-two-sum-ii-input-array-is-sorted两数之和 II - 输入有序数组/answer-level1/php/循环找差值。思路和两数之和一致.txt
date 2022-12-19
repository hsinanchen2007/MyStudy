### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $numbers
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($numbers, $target) {
       foreach($numbers as $k => $v) {
            $diff = $target - $v;
            if (!isset($found[$diff])) {
                $found[$v] = $k + 1;
                continue;
            }
            return [$found[$diff], $k+1];
        }
    }
}
```