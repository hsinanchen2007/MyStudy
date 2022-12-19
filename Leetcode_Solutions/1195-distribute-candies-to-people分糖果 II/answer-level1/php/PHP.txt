时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $candies
     * @param Integer $num_people
     * @return Integer[]
     */
    function distributeCandies($candies, $num_people) {
        $nums = [];

        for ($i = 0; $i < $num_people; $i++) {
            $nums[] = 0;
        }

        $num = 1;
        $i = 0;

        while ($candies) {
            $tmp = $candies < $num ? $candies : $num;
            $nums[$i % $num_people] += $tmp;
            $candies -= $tmp;
            $num++;
            $i++;
        }

        return $nums;
    }
}
```