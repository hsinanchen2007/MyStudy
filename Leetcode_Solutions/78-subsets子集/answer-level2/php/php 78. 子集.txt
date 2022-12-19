### 解题思路
此处撰写解题思路

### 代码
### 动态规划
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums) {
        $n = count($nums);
        if ($n == 0) return [[]];
        $dp[1] = [[], [$nums[0]]];
        for ($i = 2; $i <= $n; $i++) {
            $tmpall = [];

            for ($j = 0; $j < count($dp[$i - 1]); $j++) {
                $tmp = $dp[$i - 1][$j];
                array_push($tmp, $nums[$i-1]);
                array_push($tmpall, $tmp);
            }

            $dp[$i] = array_merge($dp[$i - 1], $tmpall);
        }

        return $dp[$n];
    }

}
```

### 回溯算法
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums)
    {
        if (count($nums) == 0) return [];
        $ans = [[], [$nums[0]]];
        $this->backtrack(1, $nums, $ans);
        return $ans;
    }

    function backtrack($n, $nums, &$ans)
    {
        if ($n == count($nums)) {
            return;
        }

        $tmpall = [];
        for ($i = 0; $i < count($ans); $i++) {
            $tmp = $ans[$i];
            array_push($tmp, $nums[$n]);
            $tmpall[] = $tmp;
        }

        $ans = array_merge($ans, $tmpall);
        $this->backtrack($n+1,$nums,$ans);

    }

}
```

参考

[参考](https://leetcode-cn.com/problems/subsets/solution/php-jie-fa-liang-chong-hui-su-jie-fa-by-andfly/)
