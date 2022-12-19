```
function numJewelsInStones($J, $S) {
    $JArray = str_split($J);
    $SArray = str_split($S);
    return count(array_intersect($SArray, $JArray));
}
```


执行结果：通过
执行用时 : 4 ms, 在所有 php 提交中击败了 97.71% 的用户
内存消耗 : 15.1 MB, 在所有 php 提交中击败了 5.51% 的用户

