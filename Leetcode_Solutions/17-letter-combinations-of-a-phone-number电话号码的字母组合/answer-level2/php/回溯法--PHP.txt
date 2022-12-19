### 解题思路
遍历不好实现。回溯法可参考官方视频。

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了88.07%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了62.07%的用户

### 代码

```php
class Solution {

    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits) {
        $keys = [
            '2' => ['a', 'b', 'c'],
            '3' => ['d', 'e', 'f'],
            '4' => ['g', 'h', 'i'],
            '5' => ['j', 'k', 'l'],
            '6' => ['m', 'n', 'o'],
            '7' => ['p', 'q', 'r', 's'],
            '8'=> ['t', 'u', 'v'],
            '9' => ['w', 'x', 'y', 'z']
        ];

        $res = [];
        if (!empty($digits)) {
            $this->backtrack('', $digits, $keys, $res);
        }

        return $res;
    }

    /**
     * @param String $combination 字母组合
     * @param String $next_digists 待处理的剩余数字
     * @param array  $keys 映射集合
     * @param array $res 结果集
     */
    public function backtrack($combination, $next_digists, $keys, &$res)
    {
        if (empty($next_digists)) {
            $res[] = $combination;
        } else {
            foreach ($keys[$next_digists[0]] as $key) {
                $this->backtrack($combination . $key, substr($next_digists, 1), $keys, $res);
            }
        }
    }
}
```

### 算法复杂度
- 时间复杂度 O(3 ^ N) 【大约是】
- 空间复杂度 O(3 ^ N) [大约是]

### 参考
[https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode/](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode/)