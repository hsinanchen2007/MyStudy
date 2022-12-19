### 解题思路
两个字符串分别压入两个栈中，然后直接比较

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了58.82%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了16.67%的用户

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @param String $T
     * @return Boolean
     */
    function backspaceCompare($S, $T) {
        $ss = $st = [];
        for ($i = 0; $i < strlen($S); $i++) {
            if ($S[$i] == '#') {
                array_pop($ss);
            } else {
                array_push($ss, $S[$i]);
            }
        }

        for ($i = 0; $i < strlen($T); $i++) {
            if ($T[$i] == '#') {
                array_pop($st);
            } else {
                array_push($st, $T[$i]);
            }
        }

        if (implode('', $ss) != implode('', $st)) {
            return false;
        }

        return true;
    }
}
```