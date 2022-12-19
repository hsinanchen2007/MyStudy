
```php
class Solution
{
    /**
     * @param Integer[] $kids
     * @param Integer[] $cookies
     * @return Integer
     */
    function findContentChildren($kids, $cookies)
    {
        sort($kids);
        sort($cookies);
        $kidsCount = count($kids);
        $cookiesCount = count($cookies);
        $k = $c = 0;
        while ($k < $kidsCount && $c < $cookiesCount) {
            if ($kids[$k] <= $cookies[$c]) $k++;
            $c++;
        }

        return $k;
    }
}
```