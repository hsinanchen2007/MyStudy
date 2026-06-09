### 解题思路
没用什么数学思路，都是用phph提供的内置方法，可以随便看看

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        //数组统计函数（统计每个值出现的次数）
        $arrNum = array_count_values($nums);
        //选择出现次数最多的值
        $max = max($arrNum);
        //通过值找到返回键
        return array_search($max, $arrNum, true);
    }
}
```