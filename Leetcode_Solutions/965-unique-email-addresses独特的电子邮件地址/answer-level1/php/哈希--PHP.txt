### 解题思路
过滤后通过hash去重

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了77.78%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $emails
     * @return Integer
     */
    function numUniqueEmails($emails) {
        $map = [];
        foreach ($emails as $email) {
            list($name, $domain) = explode('@', $email);
            list($temp_name, ) = explode('+', $name);
            $filter_name = str_replace('.', '', $temp_name);
            $map[$filter_name . '@' . $domain] = 0;
        }

        return count($map);
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度：O(N)

### 参考
