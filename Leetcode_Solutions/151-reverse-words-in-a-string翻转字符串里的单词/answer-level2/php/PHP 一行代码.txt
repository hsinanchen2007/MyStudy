```php
class Solution
{
    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s)
    {
        return implode(' ', array_filter(array_reverse(explode(' ', $s))));
    }
}
```
