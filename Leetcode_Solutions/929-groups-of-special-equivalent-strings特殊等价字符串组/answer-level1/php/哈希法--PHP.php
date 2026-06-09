### 解题思路
理解题意是关键。把一个字符串数组，拆分成多个子数组，每个子数组中的字符通过排序后是同样的字符串，这里只需要记数，通过map来去重计数即可。

### 代码

```php
class Solution {

    /**
     * @param String[] $A
     * @return Integer
     */
    function numSpecialEquivGroups($A) {
        $map = [];
        for ($i = 0; $i < count($A); $i++) {
            $s1 = $s2 = [];
            for ($j = 0; $j < strlen($A[$i]); $j++) {
                if ($j % 2 == 0) $s1[] = $A[$i][$j];
                else $s2[] = $A[$i][$j];
            }

            sort($s1);
            sort($s2);
            $map[implode('', $s1) . implode('', $s2)] = 0;
        }

        return count($map);
    }
}
```

### 算法复杂度
- 时间复杂度: O(M * N)
- 空间复杂度：O(N)

### 参考
[https://leetcode-cn.com/problems/groups-of-special-equivalent-strings/comments/94877](https://leetcode-cn.com/problems/groups-of-special-equivalent-strings/comments/94877)