### 解题思路
将res作为收纳遍历过元素的容器，如果当前元素+res的某个元素=target，就把这两个index返回

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $len = count($nums);
        $p = 0;
        $p1 = $len - 1;
        $res = [];
        for($i = 0; $i < $len; ++$i) {
            $k = isset($res[$target - $nums[$i]]) ? $res[$target - $nums[$i]] : false;
            if($k !== false) return [$k, $i];
            $res[$nums[$i]] = $i;
        }
        return null;
    }
}
```