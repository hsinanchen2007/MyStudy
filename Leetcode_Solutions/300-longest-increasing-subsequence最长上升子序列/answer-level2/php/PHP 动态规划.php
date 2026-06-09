### 解题思路
此处撰写解题思路
本题的解题方向符合动态规划的要求，即当前值大于前面的值时，f(n) = max(f(1) + 1，...f(n) + 1)否则等于1
代码如下，清晰明了
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function lengthOfLIS($nums) {
        //动态规划
        $arr = [];
        foreach ($nums as $key => $num) {
            $arr[$key] = 1;
            for ($i = 0; $i <= $key; $i ++) {
                if ($nums[$i] < $num) {
                    $arr[$key] = max($arr[$key], $arr[$i] + 1);
                }
            }
        }
        return $arr ? max($arr) : 0;
    }
}
```