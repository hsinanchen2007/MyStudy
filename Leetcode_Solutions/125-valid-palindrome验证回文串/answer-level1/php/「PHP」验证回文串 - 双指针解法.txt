**题目**

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

**思路**

设置头，尾双指针，指针向中间遍历判断字符串。跳过非数字和字母字符，满足数字或字母的字符，统一转化为小写，判断两个字符值是否相等

**实现**
```php
class Solution {
    /**
     * 双指针解法
     * 时间复杂度 O(n)
     * 空间复杂度 O(1)
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) 
    {
        $i = 0;
        $j = strlen($s) - 1;
        while($i < $j) {
            // 非数字和字符串跳过
            while ($i < $j && !ctype_alnum($s[$i])) $i++;
            while ($i < $j && !ctype_alnum($s[$j])) $j--;
            if (strtolower($s[$i]) != strtolower($s[$j])) return false;
            $i++;
            $j--;
        }
        return true;
    }
}
```