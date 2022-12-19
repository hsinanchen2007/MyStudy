### 解题思路
常规方法，遍历对每个字符串排序，排序后的字符作为key, 添加到hash中。

注意：PHP字符串没有现成的排序函数，需要转为数组，使用sort来排序。
```
// 使用str_split来转，不能使用explode
$arr = explode('', $strs[$i]);
```


### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了97.47%的用户
内存消耗 :21.7 MB, 在所有 PHP 提交中击败了32.61%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String[][]
     */
    function groupAnagrams($strs) {
        $map = [];
        for ($i = 0; $i < count($strs); $i++) {
            $arr = str_split($strs[$i]);
            sort($arr);
            $sorted_str = implode(',', $arr);
            $map[$sorted_str][] = $strs[$i];
        }

        return array_values($map);
    }
}
```

### 算法复杂度
- 时间复杂度 O(NMlog(N)), N为数组长度，M为单字符串最长长度。
- 空间复杂度 O(MN)

### 参考
[https://leetcode-cn.com/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode/](https://leetcode-cn.com/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode/)