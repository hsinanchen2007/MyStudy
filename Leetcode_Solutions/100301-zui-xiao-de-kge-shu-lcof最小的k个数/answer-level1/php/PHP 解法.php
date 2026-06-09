```php
function getLeastNumbers($arr, $k) 
{
    $n = count($arr);
    if ($n == 0) return [];
    sort($arr);
    return array_slice($arr, 0, $k);
}
```
