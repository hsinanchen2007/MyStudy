```php
function setZeroes(&$matrix)
{
    // 列
    $col = count($matrix);
    // 行
    $row = count($matrix[0]);

    // 初始化第一列没有0
    $colIs0 = false;
    // 初始化第一行没有0
    $rowIs0 = false;

    // 判断第一列是否有0
    for ($i=0; $i < $col; $i++) {
        if ($matrix[$i][0] == 0) {
            $colIs0 = true;
            break;
        }
    }

    // 判断第一行是否有0
    for ($j=0; $j < $row; $j++) {
        if ($matrix[0][$j] == 0) {
            $rowIs0 = true;
            break;
        }
    }

    // 把第一行第一列作为标志位
    for ($i=1; $i < $col; $i++) {
        for ($j=1; $j < $row; $j++) {
            if ($matrix[$i][$j] == 0) {
                $matrix[$i][0] = 0;
                $matrix[0][$j] = 0;
            }
        }
    }

    // 置0
    for ($i=1; $i < $col; $i++) {
        for ($j=1; $j < $row; $j++) {
            if ($matrix[$i][0] == 0 || $matrix[0][$j] == 0) {
                $matrix[$i][$j] = 0;
            }
        }
    }

    // 最后再处理第一行第一列为0的情况
    // 先处理列
    if ($colIs0) {
        for ($i=0; $i < $col; $i++) {
            $matrix[$i][0] = 0;
        }
    }

    // 再处理行
    if ($rowIs0) {
        for ($j=0; $j < $row; $j++) {
            $matrix[0][$j] = 0;
        }
    }

}
```
