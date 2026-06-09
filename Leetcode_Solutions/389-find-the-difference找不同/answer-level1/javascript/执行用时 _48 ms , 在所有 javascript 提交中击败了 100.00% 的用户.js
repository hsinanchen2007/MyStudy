### 解题思路
# 方法一
先排序，然后逐个比较
```
var findTheDifference = function(s, t) {
    s = s.split('').sort().join('');
    t = t.split('').sort().join('');

    for (let i = 0; i < t.length; i++) {
        if (s[i] != t[i]) {
            return t[i];
        }
    }
};
```

# 方法二
一次遍历计算出两个字符串的ASCII总和，根据差值得出插入的字符
```
var findTheDifference = function(s, t) {
    if (!s.length) return t;
    let sum1 = 0, sum2 = 0, i = 0;

    while (i < t.length) {
        if (s[i]) sum1 += s.charCodeAt(i);
        if (t[i]) sum2 += t.charCodeAt(i);
        i++;
    }
    return String.fromCharCode(sum2 - sum1);
}
```
