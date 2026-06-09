### 解题思路
算法：
1. 遍历secret，对比各位数字，记录相同的次数，即bulls，同时把不相同的数字存入map, key为数字，val为出现次数
2. 遍历guess, map中存在当前数字，记一次cows次数，同时把数字对应的次数减一，因为可能存在重复数字。
3. 返回bulls和cows。

**注意：公牛不应该出现在母牛中。**

### 性能
执行用时 :16 ms, 在所有 php 提交中击败了50.00%的用户
内存消耗 :15.1 MB, 在所有 php 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $secret
     * @param String $guess
     * @return String
     */
    function getHint($secret, $guess) {
        $map = [];
        $bulls = $cows = 0;
        for ($i = 0; $i < strlen($secret); $i++) {
            if ($secret[$i] == $guess[$i]) {
                $bulls++;
            } else {
                $map[$secret[$i]]++;
            }
        }

        for ($i = 0; $i < strlen($guess); $i++) {
            if ($map[$guess[$i]] > 0 && $guess[$i] != $secret[$i]) {
                $map[$guess[$i]]--;
                $cows++;
            }
        }

        return sprintf('%sA%sB', $bulls, $cows);
    }
}
```

### 参考
[C语言实现](https://leetcode-cn.com/problems/bulls-and-cows/solution/cyu-yan-cai-shu-zi-you-xi-by-penn-10/)