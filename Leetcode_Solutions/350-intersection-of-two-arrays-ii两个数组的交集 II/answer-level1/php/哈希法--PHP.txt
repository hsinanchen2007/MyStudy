### 解题思路
在349. 两个数组的交集这一题的基础上，记录重复元素的个数，这里重点是出现的次数要求一次，而349题要求元素唯一性。

### 性能
执行用时 :20 ms, 在所有 php 提交中击败了31.37%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了30.95%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $map = [];
        $res = [];
        for ($i = 0;$i < count($nums1); $i++) {
            $map[$nums1[$i]]++;
        }

        for ($i = 0; $i < count($nums2); $i++) {
            if ($map[$nums2[$i]]  > 0) {
                $res[] = $nums2[$i];
                $map[$nums2[$i]]--;;
            }
        }

        return $res;
    }
}
```