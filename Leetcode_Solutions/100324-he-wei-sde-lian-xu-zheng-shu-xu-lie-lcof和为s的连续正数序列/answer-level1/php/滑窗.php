### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $target
     * @return Integer[][]
     */
    function findContinuousSequence($target) {
        $i = 1; $j = 2; $res = [];
        while($j <= ceil($target / 2)){
            // 算出目前窗口的和
            $sum = (($j - $i + 1) * ($j + $i)) / 2;
            if($sum < $target){
                // 滑动窗口向右移动
                $j += 1;
            } elseif($sum > $target) {
                $i += 1;
            } else {
                $res[] = range($i,$j);
                $j += 1;
                $i++;
            }
        }
        return $res;
    }
}
```