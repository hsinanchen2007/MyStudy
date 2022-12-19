### 解题思路
此处撰写解题思路
先排序，再取最小的前k个数
### 代码

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        //排序取值
        sort($arr);
        return array_slice($arr,0,$k);
        
    }
}
```