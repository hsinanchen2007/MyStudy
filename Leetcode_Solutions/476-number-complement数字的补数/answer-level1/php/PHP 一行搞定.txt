```php
/**
 * @param Integer $num
 * @return Integer
 */
function findComplement3($num) {
    return pow(2, strlen(decbin($num))) - 1 - $num;
}
```
