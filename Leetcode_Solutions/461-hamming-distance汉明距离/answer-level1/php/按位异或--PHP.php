### 解题思路
异或的结果是1，统计有多少个1即可。

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @param Integer $y
     * @return Integer
     */
    function hammingDistance($x, $y) {
        return substr_count(decbin($x ^ $y), '1');
    }
}
```

参考：
[decbin](https://www.php.net/manual/zh/function.decbin)
[substr_count](https://www.php.net/manual/zh/function.substr-count)