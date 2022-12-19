### 解题思路
投机取巧的解法，利用先用函数
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        //计算每个值出现的次数
        $arrs = array_count_values($nums);
        //返回最大值对应的key
        return array_flip($arrs)[max($arrs)];
    }
}
```