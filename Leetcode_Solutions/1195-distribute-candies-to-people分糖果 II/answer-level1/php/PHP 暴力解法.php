数学解法看着脑壳疼

```php
class Solution
{
    /**
     * @param Integer $candies
     * @param Integer $num_people
     * @return Integer[]
     */
    function distributeCandies($candies, $num_people)
    {
        $result = array_fill(0, $num_people, 0);
        if ($candies <= 0) {
            return $result;
        }

        // 轮次
        $round = 1;
        while ($candies) {
            for ($i = 0; $i < $num_people; ++$i) {
                $need = $num_people * ($round - 1) + ($i + 1);
                if ($candies <= $need) {
                    $result[$i] += $candies;
                    $candies = 0;
                    break;
                }
                $result[$i] += $need;
                $candies -= $need;
            }
            $round++;
        }

        return $result;
    }
}
```