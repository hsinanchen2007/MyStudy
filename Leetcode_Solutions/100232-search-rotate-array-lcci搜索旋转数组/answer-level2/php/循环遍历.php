### 解题思路
感觉题目怪怪的

### 代码

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $target
     * @return Integer
     */
    function search($arr, $target) {
        for ($i = 0; $i < count($arr); $i++) {
            if ($target == $arr[$i]) {
                return $i;
            }
        }
        return -1;
    }
}
```