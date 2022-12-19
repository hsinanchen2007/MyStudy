### 解题思路
不知道能不能使用内置函数，否则就遍历替换即可。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function replaceSpace($s) {
        return str_replace(' ', '%20', $s);
    }
}
```