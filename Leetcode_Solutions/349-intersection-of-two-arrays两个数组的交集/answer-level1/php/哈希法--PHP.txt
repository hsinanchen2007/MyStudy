### 解题思路
把一个数组存到hash中，遍历另一个数组，检查是否在哈希中，在的话就是目标元素，同时为了唯一性删除哈希中已存在元素。

### 性能
执行用时 :24 ms, 在所有 php 提交中击败了13.19%的用户
内存消耗 :15.2 MB, 在所有 php 提交中击败了8.11%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {
        $map = [];
        $res = [];
        for ($i = 0;$i < count($nums1); $i++) {
            $map[$nums1[$i]] = true;
        }

        for ($i = 0; $i < count($nums2); $i++) {
            if ($map[$nums2[$i]]) {
                $res[] = $nums2[$i];
                unset($map[$nums2[$i]]);
            }
        }

        return $res;
    }
}
```