```php
function sortArrayByParityII($a)
{
    $count = count($a);
    if ($count == 0) {
        return [];
    }

    // 原地双指针替换， O(1) 空间复杂度
    $even = 0; // 偶数指针下标
    $odd = 1; // 奇数指针下标
    for (; $even < $count; $even += 2) {
        if ($a[$even] % 2 == 1) { // 在偶数位置找到奇数
            // 在奇数位置去找偶数，进行替换
            while ($a[$odd] % 2 == 1) {
                $odd += 2;
            }

            $tmp = $a[$even];
            $a[$even] = $a[$odd];
            $a[$odd] = $tmp;
        }
    }

    return $a;
}
```
