### 解题思路
不知道说些什么

### 代码

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        sort($arr);
        return array_slice($arr,0,$k);
    }
}
```