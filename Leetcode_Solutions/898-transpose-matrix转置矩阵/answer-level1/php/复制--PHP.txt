### 解题思路
开始考虑[斜着遍历](http://niliu.me/articles/1730.html)，然后交换，看来比较麻烦，定义新的数组，遍历的时候从新复制即可。

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了62.50%的用户
内存消耗 :16.2 MB, 在所有 PHP 提交中击败了93.33%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $A
     * @return Integer[][]
     */
    function transpose($A) {
        $row = count($A);
        $col = count($A[0]);

        $res = [];
        for ($i = 0; $i < $row; $i++) {
            for ($j = 0; $j < $col; $j++) {
                $res[$j][$i] = $A[$i][$j];
            }
        }

        return $res;
    }
}
```

### 算法复杂度
- 时间复杂度：O(M * N)
- 空间复杂度: O(M * N)

### 参考
[https://leetcode-cn.com/problems/transpose-matrix/solution/zhuan-zhi-ju-zhen-by-leetcode/](https://leetcode-cn.com/problems/transpose-matrix/solution/zhuan-zhi-ju-zhen-by-leetcode/)