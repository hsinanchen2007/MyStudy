### 解题思路
此处撰写解题思路
本题的解决思路可以按照动态规划来看，所以公式是很重要的，即F(n) = max(F(n -1) + num[n], num[n]);
按照此公式计算就好
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSubArray($nums) {
        $arr = [$nums[0]];
        $count = count($nums);
        for ($i = 1; $i < $count; $i ++) {
            $arr[$i] = max($arr[$i - 1] + $nums[$i], $nums[$i]);
        }
        
        return max($arr);
    }
}
```