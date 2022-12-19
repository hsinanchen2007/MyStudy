### 解题思路
把两句话合并后统计单词数，筛选出出现一次的。

注意没必要用两个map

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了81.82%的用户
内存消耗 :14.6 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $A
     * @param String $B
     * @return String[]
     */
    function uncommonFromSentences($A, $B) {
        $str = $A . ' ' . $B;
        $words = explode(' ', $str);
        $map = [];
        foreach ($words as $word) {
            $map[$word] = isset($map[$word]) ? $map[$word] + 1 : 1;
        }

        $res = [];
        foreach ($map as $word => $count) {
            if ($count == 1) $res[] = $word;
        }

        return $res;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度：O(N)

### 参考