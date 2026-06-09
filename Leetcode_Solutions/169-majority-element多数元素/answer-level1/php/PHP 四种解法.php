### 解法一 参考官方题解第二种方法，取排序后的数组中间元素即可

```php
function majorityElement($nums)
{
    sort($nums);
    return $nums[floor(count($nums) / 2)];
}
```

### 解法二 统计每个元素出现的次数，找出出现次数最多的
```php
function majorityElement($nums)
{
    // 内置函数
    $count = array_count_values($nums);
    return array_search(max($count), $count);
}
```

### 解法三 同解法二 使用一个 hash table 存储遍历的元素
```php
 function majorityElement($nums)
{
    // hash table
    $hash = [];
    foreach ($nums as $num) {
        if (!isset($hash[$num])) $hash[$num] = 0;
        $hash[$num]++;
    }
    return array_search(max($hash), $hash);
}
```

### 解法四 使用一个辅助栈 栈为空则入栈，栈不为空，如果与栈顶元素不相同则出栈，最后栈顶元素就是要找的
```php
function majorityElement($nums)
{
    // Stack 开心消消乐
    $stack = [];
    foreach ($nums as $num) {
        if (empty($stack) || end($stack) == $num) {
            $stack[] = $num;
        } else {
            array_pop($stack);
        }
    }

    return end($stack);
}
```
