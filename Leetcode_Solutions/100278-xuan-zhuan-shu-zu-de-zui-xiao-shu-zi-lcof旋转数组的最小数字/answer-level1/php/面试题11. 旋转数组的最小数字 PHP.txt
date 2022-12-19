### 解题思路
1. 可使用打擂，比较简单，时间复杂度为 n
2. 二分缩小范围，中间那点和右边那点比较，用于缺点断点在哪(和左边比较的话，case比较多，因为是递增的所以和右边比较的话则只有断点在、断点不在两种情况，而不用考虑自增的因素)
3. 遇到特殊情况：中间和右边两个一致，可以舍弃右边那个(不影响结果)
### 代码

```php
class Solution {

    /**
     * @param Integer[] $numbers
     * @return Integer
     */
    function minArray($numbers) {
      $count = count($numbers);

        if($count == 1) {
            return $numbers[0];
        }

        $min = 0;
        $max = $count - 1;


        while(true) {
            $mid = intval(0.5 * ($min + $max));
            if($numbers[$mid] < $numbers[$max]) {
                $max = $mid;
            } else if ($numbers[$mid] > $numbers[$max]){
                $min = $mid;
            } else {
                // 特殊情况，中间和右边两个一致，则可以舍弃右边那个
                $max -= 1;
            }
       
            if($max - $min < 2) {break;}
        }

        return  $numbers[$max] > $numbers[$min] ? $numbers[$min] : $numbers[$max];
    }
}
```