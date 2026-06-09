```
function subtractProductAndSum($n)
{
    $n = str_split(strval($n));
    return intval(array_product($n) - array_sum($n));
}
```

执行结果：通过
执行用时 : 4 ms, 在所有 php 提交中击败了100.00%的用户
内存消耗 : 15.1 MB, 在所有 php 提交中击败了100.00%的用户