### 解题思路
我的理解是仅交换A字符串中的两个字符一次，还必须交换一次，交换后 A == B

所以分两种情况：
0、A == B : A中至少有重复2次的字母。ab和ba是不满足的。
1、A != B : AB中只能存在2处字母不对应的情况，因为只能交换一次。

算法：
1. 检查A、B长度，不相等，返回false。
2. 考虑A == B的情况。
3. 考虑A != B的情况。

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了68.75%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了50.00%的用户


### 代码

```php
class Solution {

    /**
     * @param String $A
     * @param String $B
     * @return Boolean
     */
    function buddyStrings($A, $B) {
        if (strlen($A) != strlen($B)) {
            return false;
        }

        $map = [];
        if ($A == $B) {
            for ($i = 0;$i < strlen($A); $i++) {
                if (in_array($A[$i], $map)) {
                    return true;
                } else {
                    $map[] = $A[$i];
                }
            }

            return false;
        } else {
            $first = $second = -1;
            for ($i = 0; $i < strlen($A); $i++) {
                if ($A[$i] != $B[$i]) {
                    if ($first == -1) {
                        $first = $i;
                    } elseif ($second == -1) {
                        $second = $i;
                    } else {
                        return false;
                    }
                }
            }

            return ($second != -1) && $A[$first] == $B[$second] && $A[$second] == $B[$first];
        }
    }
}
```

### 参考
[https://leetcode-cn.com/problems/buddy-strings/solution/javajian-ji-ming-liao-ban-by-dreshadow/](https://leetcode-cn.com/problems/buddy-strings/solution/javajian-ji-ming-liao-ban-by-dreshadow/)
[https://leetcode-cn.com/problems/buddy-strings/solution/qin-mi-zi-fu-chuan-by-leetcode/](https://leetcode-cn.com/problems/buddy-strings/solution/qin-mi-zi-fu-chuan-by-leetcode/)