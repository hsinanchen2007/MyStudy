### 解题思路
挨个遍历，如果是1，周长+4，然后过滤左边相邻和上边相邻的边，分别-2.

### 性能
执行用时 :184 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :17.2 MB, 在所有 PHP 提交中击败了33.33%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function islandPerimeter($grid) {
        $perimeter = 0;
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[$i]); $j++) {
                if ($grid[$i][$j] == 1) {
                    $perimeter += 4;
                    if ($j > 0 && $grid[$i][$j - 1] == 1) {
                        $perimeter -= 2;
                    }

                    if ($i > 0 && $grid[$i - 1][$j] == 1) {
                        $perimeter -= 2;
                    }
                }
            }
        }

        return $perimeter;
    }
}
```