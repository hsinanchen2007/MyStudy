### 解题思路

当 n = 1 时 直接返回一个数的排列。

循环 n 次，

每次先取出一个数 $a ，在排列出剩下 n-1 个数的全排列（递归）

再将 $a 添加到 每个排列中

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permute($nums) {
        $r = [];
        $len = count($nums);

        if ($len == 1) {
            $r[] = $nums;
            return $r;
        }

        foreach ($nums as $k => $v) {
            $arr = $nums;
            array_splice($arr, $k, 1);
            $rr = $this->permute($arr);

            foreach ($rr as $item) {
                array_unshift($item, $v);
                $r[] = $item;
            }
        }
        return $r;
    }
}
```