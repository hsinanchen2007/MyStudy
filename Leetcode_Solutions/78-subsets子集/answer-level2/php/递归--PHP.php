### 解题思路
递归, 详情可以见[个人博客](http://niliu.me/articles/1375.html)

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了25.40%的用户
内存消耗 :15.6 MB, 在所有 PHP 提交中击败了43.10%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums) {
        $res = [];
        if (count($nums) < 1)  {
            $res = [[]];
            return $res;
        }

        $head = array_shift($nums);
        $other_sets = $this->subsets($nums);
        foreach ($other_sets as $other_set) {
            $res[] = array_merge((array)$head, (array)$other_set);
        }

        return array_merge($res, $other_sets);
    }
}
```