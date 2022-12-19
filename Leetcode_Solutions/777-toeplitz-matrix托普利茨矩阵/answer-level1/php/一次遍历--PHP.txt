### 解题思路
只需判断：前行中除最后一个元素外剩余的元素完全等于后行中除第一个元素外剩余的元素。

### 性能
执行用时 :32 ms, 在所有 PHP 提交中击败了75.00%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了54.55%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return Boolean
     */
    function isToeplitzMatrix($matrix) {
        for ($i = 0; $i < count($matrix) - 1; $i++) {
            if (array_slice($matrix[$i], 0, -1) != array_slice($matrix[$i + 1], 1)) return false;
        }

        return true;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/toeplitz-matrix/comments/66888](https://leetcode-cn.com/problems/toeplitz-matrix/comments/66888)