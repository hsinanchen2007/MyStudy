 执行用时 :124 ms, 在所有 javascript 提交中击败了7.50% 的用户
 内存消耗 :38.7 MB, 在所有 javascript 提交中击败了56.25%的用户
暴力法

```
var isSubsequence = function(s, t) {
    let i = 0,j = 0;
    for (; i < s.length && j < t.length; ) {//i遍历s子序列，j遍历t
        if(s[i]===t[j]){i++;j++}
        else{j++}
    }
    if(i===s.length)
        return true;
    return false;
};
```


`
