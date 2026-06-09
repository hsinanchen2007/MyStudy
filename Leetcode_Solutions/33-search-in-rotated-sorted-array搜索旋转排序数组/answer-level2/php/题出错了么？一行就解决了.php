### 解题思路
是我没看懂题目还是题目有问题，直接弹回目标值的Index就结束了，如果没有则弹回-1
![Screen Shot 2020-03-16 at 8.50.25 AM.png](https://pic.leetcode-cn.com/30e497fbec9f0c0897f5cf11767406ca081fdd41eabd77e44d578cd0770a7638-Screen%20Shot%202020-03-16%20at%208.50.25%20AM.png)


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        in_array($target, $nums) ? $key = array_search($target, $nums) : $key = -1;
        return $key;
    }
}
```