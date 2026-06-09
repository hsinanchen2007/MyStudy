### 解题思路
通过栈来检查一个原语，记录开始和结束位置下标，截取字符串拼接。

注意截取的长度：($end - $start) - 1

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了92.68%的用户
内存消耗 :15.2 MB, 在所有 php 提交中击败了100%的用户

注：多次提交时间不一样

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function removeOuterParentheses($S) {
        $start = $end = 0;
        $stack = [];
        $flag = false;

        $res = '';
        for ($i = 0; $i < strlen($S); $i++) {
            if ($S[$i] == '(') {
                if (!$flag) {
                    $flag = true;
                    $start = $i;
                }
                array_push($stack, $S[$i]);
            }

            if ($S[$i] == ')') {
                array_pop($stack);
                if (empty($stack)) {
                    $flag = false;
                    $end = $i;

                    $res .= substr($S, $start + 1, ($end - $start) - 1);
                }
            }
        }

        return $res;
    }
}
```