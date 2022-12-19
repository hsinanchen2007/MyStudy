### 解题思路
dfs，注意这里是N个人，不能使用第200题岛屿数量的方式。

### 性能
执行用时 :76 ms, 在所有 PHP 提交中击败了69.23%的用户
内存消耗 :17.1 MB, 在所有 PHP 提交中击败了71.43%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $M
     * @return Integer
     */
    function findCircleNum($M) {
        $visitor = [];
        $count = 0;
        for ($i = 0; $i < count($M); $i++) {
            if ($visitor[$i] == 0) {
                $this->dfs($M, $visitor, $i);
                $count++;
            }
        }

        return $count;
    }

    public function dfs(&$M, &$visitor, $i)
    {
        for ($j = 0; $j < count($M); $j++) {
            if ($M[$i][$j] == 1 && $visitor[$j] == 0) {
                $visitor[$j] = 1;
                $this->dfs($M, $visitor, $j);
            }
        }
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N)

### 参考
[https://www.cnblogs.com/grandyang/p/6686983.html](https://www.cnblogs.com/grandyang/p/6686983.html)
[https://leetcode-cn.com/problems/friend-circles/solution/php-dfs-ti-jie-by-aliliin/](https://leetcode-cn.com/problems/friend-circles/solution/php-dfs-ti-jie-by-aliliin/)