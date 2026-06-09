### 1. 找一条线，两个矩形在线两侧，则不重叠

```php
function isRectangleOverlap($rec1, $rec2)
{
    if ($rec2[2] <= $rec1[0] || $rec2[3] <= $rec1[1] || $rec2[0] >= $rec1[2] || $rec2[1] >= $rec1[3]) return false;

    return true;
}
```

### 2. 分别向 x，y 轴投影，都有重合才可以

```php
function isRectangleOverlap($rec1, $rec2)
{
    // 投影法
    $xOverlap = !($rec1[2] <= $rec2[0] || $rec1[0] >= $rec2[2]);
    $yOverlap = !($rec1[3] <= $rec2[1] || $rec1[1] >= $rec2[3]);

    return $xOverlap && $yOverlap;
}
```

