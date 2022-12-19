时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $moves
     * @return Boolean
     */
    function judgeCircle($moves) {
        $x = 0;
        $y = 0;

        for ($i = 0, $length = strlen($moves); $i < $length; $i++) {
            switch ($moves[$i]) {
                case 'L':
                    $x--;
                    break;
                case 'R':
                    $x++;
                    break;
                case 'U':
                    $y++;
                    break;
                case 'D':
                    $y--;
                    break;
            }
        }

        return $x == 0 && $y == 0;
    }
}
```