### 解题思路
从后往前遍历，如果当前元素不是0，必然可以到达下一步，否则为0，就看这个元素前面的元素是否可以跳过这个0(可以理解为抹平0，0就是一个坑，跳过去了就success, 否则就掉坑fail).

**注意：把0看成坑，如果没有0，就是没有坑，一路平坦走到最后，否则就看能不能跳过坑。程序人生，这题很有意义。**

### 性能
执行用时 :32 ms, 在所有 PHP 提交中击败了30.65%的用户
内存消耗 :18.3 MB, 在所有 PHP 提交中击败了46.81%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function canJump($nums) {
        $step = 1;
        for ($i = count($nums) - 2; $i >= 0; $i--) {
            if ($nums[$i] >= $step) $step = 1;
            else $step++;
        }

        return $step == 1;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/jump-game/comments/6694](https://leetcode-cn.com/problems/jump-game/comments/6694)