```php
class Solution
{
    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParity($A)
    {
        // double pointers, 原地排序
        $len = count($A);
        $left = 0;
        $right = $len - 1;
        while ($left < $right) {
            while ($left < $right && $A[$left] % 2 == 0) {
                $left++;
            }

            while ($left < $right && $A[$right] % 2 == 1) {
                $right--;
            }

            $tmp = $A[$left];
            $A[$left] = $A[$right];
            $A[$right] = $tmp;
            $left++;
            $right--;
        }

        return $A;
    }
}
```
