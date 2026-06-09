### 解题思路
双指针模拟加法

**注意：$sum / 10， PHP除是小数。**

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了75.00%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了85.71%的用户

### 代码

```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function addStrings($num1, $num2) {
        $p1 = strlen($num1) - 1;
        $p2 = strlen($num2) - 1;

        $carry = 0;
        $res = '';

        while ($p1 >= 0 OR $p2 >= 0) {
            $n1 = $p1 >= 0 ? $num1[$p1] : 0;
            $n2 = $p2 >= 0 ? $num2[$p2] : 0;

            $sum = $n1 + $n2 + $carry;
            $carry = intval($sum / 10);
            $res = ($sum % 10) . $res;
            $p1--;
            $p2--;
        }

        if ($carry > 0) {
            $res = $carry . $res;
        }

        return $res;
    }
}
```

参考：
[字符串相加](https://leetcode-cn.com/problems/add-strings/solution/add-strings-shuang-zhi-zhen-fa-by-jyd/)