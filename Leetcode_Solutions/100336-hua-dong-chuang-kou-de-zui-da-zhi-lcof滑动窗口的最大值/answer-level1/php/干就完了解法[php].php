### 解题思路
贴一个比较low的解法^_^

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function maxSlidingWindow($nums, $k) {
        $i=0;
        $j=$k-1;
        $rs=[];
        while($j<count($nums)){
            $window = array_slice($nums,$i,$k);
            $max = max($window);
            $rs[]=$max;
            $i++;
            $j++;
        }
        return $rs;
    }
}
```