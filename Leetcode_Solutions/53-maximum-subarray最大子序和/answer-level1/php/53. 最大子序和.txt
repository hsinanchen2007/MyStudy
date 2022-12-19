### 解题思路
贪心算法

1. 当前元素
2. 当前位置总和
3. 最大值

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSubArray($nums) {
        //初始化当前位置总和、最大值
        $curSum = $maxSum = $nums['0'];
        
        for($i=1; $i<count($nums); $i++){
            $curSum = ($curSum + $nums[$i]) > $nums[$i] ?  ($curSum + $nums[$i]) : $nums[$i];
            $maxSum = $maxSum > $curSum ? $maxSum : $curSum;
        }
        return $maxSum;
    }
}
```