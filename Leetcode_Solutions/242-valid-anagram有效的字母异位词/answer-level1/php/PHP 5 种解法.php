### 解题思路
1. 对两个字符串进行排序，再比较是否相等（注意 PHP的排序算法是原地排序，引用传值，返回结果为 bool 值）
2. 使用一个辅助哈希表，PHP 中使用数组即可。遍历两个字符串，一个增加，一个减少，最后看数组中的值是否都为零
3. 同样使用数组，不过是二维数组，与方法二类似，只是不需要记录每个字母出现的次数，也不需要二次遍历。空间换时间。
4. 使用 PHP 内置字符串 count_chars 函数，效率最高。
5. 使用 PHP 内置数组 array_count_values 函数，需要将字符串处理为数组，效率比方法 4 略低。

特殊情况：两个字符串长度不相等，就没必要再进行处理了。

### 代码 1

```php
function isAnagram1($s, $t)
{
    $s = str_split($s, 1);
    $t = str_split($t, 1);
    sort($s);
    sort($t);
    return $s == $t;
}
```

### 代码 2

```php
function isAnagram($s, $t) {
    if (strlen($s) != strlen($t)) {
        return false;
    }

    $hash = [];
    for ($i = 0; $i < strlen($s); ++$i) {
        if (!isset($hash[$s[$i]])) {
            $hash[$s[$i]] = 1;
        } else {
            $hash[$s[$i]]++;
        }

        if (!isset($hash[$t[$i]])) {
            $hash[$t[$i]] = -1;
        } else {
            $hash[$t[$i]]--;
        }
    }

    foreach ($hash as $v) {
        if ($v != 0) {
            return false;
        }
    }

    return true;
}
```

### 代码 3

```php
function isAnagram($s, $t)
{
    if (strlen($s) != strlen($t)) {
        return false;
    }

    if ($s == $t) {
        return true;
    }

    $sArr = $tArr = [];
    for ($i = 0; $i < strlen($s); $i++) {
        $sArr[$s[$i]][] = $s[$i];
        $tArr[$t[$i]][] = $t[$i];
    }

    return $sArr == $tArr;
}
```

### 代码 4

```php
function isAnagram($s, $t)
{
    // 效率最高
    // Return information about characters used in a string https://www.php.net/manual/en/function.count-chars.php
    return count_chars($s, 1) == count_chars($t, 1);
}
```

### 代码 5

```php
function isAnagram($s, $t)
{
    // array_count_values — Counts all the values of an array
    return array_count_values(str_split($s, 1)) == array_count_values(str_split($t, 1));
}
```