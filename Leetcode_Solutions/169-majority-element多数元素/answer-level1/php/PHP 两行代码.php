### 解题思路
此处撰写解题思路
先排序，取中位数的元素即为多数元素
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        sort($nums);
        return $nums[(int)(count($nums) / 2)];
    }
}
```