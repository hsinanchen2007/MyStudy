**解题思路：**

使用 `array_shift` 模仿队列

先创建字典：

```php
$dic = ["0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];
```



再创建一个用于模拟队列的数组

```php
// 一定要设置一个初始空值，否则后面会报错
$resultList = [''];
```



循环处理输入的值

```php
for ($i=0; $i < strlen($digits); $i++) { 
    // 先获取当前$i对应的输入的字符串
    // 再使用intval 转成整形，用于后面根据键值对取对应的字符串
    $mappIndex = intval($digits[$i]);

    // 总是判断当前$resultList的第一个元素的字符长度是否等于当前$i
    while (strlen($resultList[0]) == $i) {
        // 将数组$resultList开头的单元移出数组
        $head = array_shift($resultList);
        $str = $dic[$mappIndex];

        for ($j=0; $j < strlen($str); $j++) { 
            $resultList[] = $head.$str[$j];
        }
    }

}
```



**解析：**

` while (strlen($resultList[0]) == $i)` 条件是用于控制往数组 `$resultList` 中添加元素。

比如（以该题为例）：

- 当 `$i = 0` 时

`strlen($resultList[0])` 的长度也为0，因为一开始初始化数组 `$resultList` 的时候，我们为其添加了一个空值，因此符合条件。

这时候，`$head` = 为空值，`$str` 根据字典 `$dic` 取出字符串 `abc`

然后 `for` 循环后得出的数组 `$resultList` 为

```php
[
    0 => 'a',
    1 => 'b',
    2 => 'c'
]
```



- 当 `$i = 1` 时

`strlen($resultList[0])` 的长度也为0，因此符合条件。

此时，`$head = 'a'`，`$str` 根据字典 `$dic` 取出字符串 `def`

然后`for` 循环后得出的数组 `$resultList` 为

```php
[
    0 => 'b',
    1 => 'c',
   	2 => 'ad',
    3 => 'ae',
    4 => 'af'
]
```

此时，当前数组仍然满足条件 `while (strlen($resultList[0]) == $i)`，因此将继续将第一个元素 `array_shift` 出来，继续操作。

因此，最后得出的数组 `$resultList` 为

```php
["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```



完整代码：

```php
function letterCombinations($digits)
{
    if (empty($digits)) {
        return [];
    }

    // 先创建字典
    $dic = ["0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];

    // 创建一个用于模拟队列的数组
    $resultList = [''];

    // 循环输入$digits
    for ($i=0; $i < strlen($digits); $i++) {
        // 先获取当前$i对应的输入的字符串
        // 再使用intval 转成整形，用于根据键值对取对应的字符串
        $mappIndex = intval($digits[$i]);

        // 总是判断当前$resultList的第一个元素的字符长度是否等于当前$i
        while (strlen($resultList[0]) == $i) {
            // 将数组$resultList开头的单元移出数组
            $head = array_shift($resultList);
            $str = $dic[$mappIndex];

            for ($j=0; $j < strlen($str); $j++) {
                $resultList[] = $head.$str[$j];
            }

            print_r($resultList);
        }

    }

    return $resultList;
}
```
