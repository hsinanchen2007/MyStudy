### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $a
     * @param Integer $b
     * @return Integer
     */
    function maximum($a, $b) {

        $arr = [$a,$b];
        rsort($arr,1);
        return $arr[0];
    }
}
```