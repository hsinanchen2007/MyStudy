### 解题思路
1. 统计字符串中每个字母出现的次数，这里有两种方式，一是将字符串打散成数组，再统计数组中每个字符出现的次数 `$arr = array_count_values(str_split($s, 1));` 二是直接统计，但是空间复杂度较高，属于空间换时间 `$arr = count_chars($s);`
2. 如果该字符出现的次数为偶数，直接全部添加
3. 如果为奇数，减一后添加，并标记有奇数个字符出现，因为回文串最中心的字符可以为单独的一个
4. 如果只出现一次，也标记奇数个字符出现
5. 返回结果。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $arr = array_count_values(str_split($s, 1));
        $return = 0;
        $hasOdd = false;
        foreach ($arr as $count) {
            if ($count % 2 == 0) {
                // 成对出现，直接添加
                $return += $count;
            } elseif ($count > 2) {
                // 奇数个，取成对的
                $return += $count - 1;
                $hasOdd = true;
            } else {
                // 只有一个
                $hasOdd = true;
            }
        }

        return $hasOdd ? ++$return : $return;
    }
}
```