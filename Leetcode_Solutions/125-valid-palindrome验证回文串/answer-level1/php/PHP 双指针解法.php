```php
function isPalindrome($s)
{
    $i = 0;
    $j = strlen($s) - 1;
    while ($i < $j) {
        // 非数字和字符串跳过
        // ctype_alnum ( string $text ) : bool
        // Checks if all of the characters in the provided string, text, are alphanumeric.
        while ($i < $j && !ctype_alnum($s[$i])) $i++;
        while ($i < $j && !ctype_alnum($s[$j])) $j--;
        if (strtolower($s[$i]) != strtolower($s[$j])) return false;
        $i++;
        $j--;
    }
    return true;
}
```
