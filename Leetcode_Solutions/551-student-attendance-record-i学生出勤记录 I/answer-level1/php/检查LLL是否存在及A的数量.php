### 解题思路
分两个方面检查，如果出现LLL，返回false, 如果出现2个A，返回false.

### 性能
执行用时 :0 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :15.2 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function checkRecord($s) {
        $count = 0;
        if (substr_count($s, 'LLL') > 0) return false;

        for ($i = 0; $i < strlen($s) && $count < 2; $i++) {
            if ($s[$i] == 'A') $count++;
        }

        return $count < 2; 
    }
}
```

参考：
[leetcode官方](https://leetcode-cn.com/problems/student-attendance-record-i/solution/xue-sheng-chu-qin-ji-lu-i-by-leetcode/)