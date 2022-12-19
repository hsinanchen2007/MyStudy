### 解题思路
先排序，再按下标取出来

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
        $min_arr = array_slice($arr, 0, $k);
        return $min_arr;
    }
}
```
提交结果如下：
![image.png](https://pic.leetcode-cn.com/29d0a2eaafb3e2ae6c3720744f511829d931a36333cdaba249a889ad2a74d4f9-image.png)
PHP太流氓了