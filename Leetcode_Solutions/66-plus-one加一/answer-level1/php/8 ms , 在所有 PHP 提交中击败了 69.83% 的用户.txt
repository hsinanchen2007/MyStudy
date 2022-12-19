### 解题思路
分三种情况讨论

### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
function plusOne($digits)
{
    $len = count($digits);

    //1. [9,9,9]
    if(array_count_values($digits)[9] == $len)
    {
        $digits[0] = 1;
        for ($i=1; $i<$len;$i++)
        {
            $digits[$i] = 0;
        }
        $digits[] = 0;
        return $digits;
    }

    //2.  [1,9,9]
    if ($digits[$len - 1] == 9) {
        $sumOf9 = 0;
        for ($i = $len - 1; $i >= 0; $i--) {
            if ($digits[$i] == 9)
                $sumOf9++;
            if ($digits[$i] != 9)
                break;
        }

        echo "sum9=" . $sumOf9;
        if ($sumOf9 > 0) {
            $j = 1;
            while ($sumOf9 > 0) {
                $digits[$len - $j] = 0;
                $sumOf9--;
                $j++;
            }
            $digits[$len - $j] += 1;
        }

    }

    //3. [1,2,4]
    else
        $digits[$len - 1]++;

    return $digits;
}
}
```