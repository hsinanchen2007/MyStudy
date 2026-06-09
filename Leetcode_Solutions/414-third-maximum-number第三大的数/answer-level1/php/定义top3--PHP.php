### 解题思路
定义top3， 一次遍历，修复top3的值。

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了94.29%的用户
内存消耗 :16.1 MB, 在所有 PHP 提交中击败了83.33%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function thirdMax($nums) {
        $top1 = $top2 = $top3 = PHP_INT_MIN;
        $flag = 0;
        $tag = false;
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] == PHP_INT_MIN && $tag == false) {
                $flag++;
                $tag = true;
            }

            if ($nums[$i] > $top1) {
                $top3 = $top2;
                $top2 = $top1;
                $top1 = $nums[$i];
                
                $flag++;
            } elseif ($top2 < $nums[$i] && $nums[$i] < $top1) {
                $top3 = $top2;
                $top2 = $nums[$i];

                $flag++;
            } elseif ($top3 < $nums[$i] && $nums[$i] < $top2) {
                $top3 = $nums[$i];

                $flag++;
            }
        }

        return $flag >= 3 ? $top3 : $top1;
    }
}
```

### 参考
[Java O(n)算法](https://leetcode-cn.com/problems/third-maximum-number/comments/11539)