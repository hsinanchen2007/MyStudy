### 解题思路
两次遍历的思路很容易想到，只是需要额外的存储空间。

这里使用双指针。
定义两个指针i, j分别指向偶数节点的位置和奇数节点的位置。遍历偶数节点的位置，如果不是偶数，移动指针j在奇数位置上找到第一个偶数，进行交换。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParityII($A) {
        for ($i = 0, $j = 1; $i < count($A); $i += 2) {
            if ($A[$i] % 2 != 0) {
                // 找到偶数为止
                while ($A[$j] % 2 != 0) {
                    $j += 2;
                }

                $tmp = $A[$i];
                $A[$i] = $A[$j];
                $A[$j] = $tmp;                
            }
        }

        return $A;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度：O(1)

### 参考
[https://leetcode-cn.com/problems/sort-array-by-parity-ii/solution/an-qi-ou-pai-xu-shu-zu-ii-by-leetcode/](https://leetcode-cn.com/problems/sort-array-by-parity-ii/solution/an-qi-ou-pai-xu-shu-zu-ii-by-leetcode/)