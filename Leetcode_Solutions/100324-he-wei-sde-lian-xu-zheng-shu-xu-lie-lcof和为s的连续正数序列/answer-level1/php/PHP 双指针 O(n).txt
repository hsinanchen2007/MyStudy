### 解题思路
此处撰写解题思路
本题可以用暴力法求解，但是太过暴力；我的解法思路比较清晰，即采用双指针方式，首先声明一个1~target的数组，然后双指针从头遍历该数组，右指针遍历的终止条件是大于等于target，此时将结果集数组头pop元素，直到结果集数组小于等于target。时间复杂度O(n)
### 代码

```php
class Solution {

    /**
     * @param Integer $target
     * @return Integer[][]
     */
    function findContinuousSequence($target) {
        $arr = $tmp = [];
        $end = 1;
        for ($start = 1; $start <= $target; $start ++) {
            if ($tmp) {
                array_shift($tmp);
                $sum = array_sum($tmp);
                if ($sum == $target) {
                    $arr[] = $tmp;
                    continue;
                } elseif ($sum > $target) {
                    continue;
                }
            }
            while ($end < $target) {
                $tmp[] = $end;
                $sum = array_sum($tmp);
                $end ++;
                if ($sum == $target) {
                    $arr[] = $tmp;
                    break;
                } elseif ($sum > $target) {
                    break;
                }
            }
        }
        return $arr;
    }
}
```