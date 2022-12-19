*法一：借用字符串*

1. 将原字符串给出拷贝一遍组成新字符串；
2. 掐头去尾留中间；
3. 如果还包含原字符串，则满足题意。

**举例:**

- s = abc|abc; // 2abc
- s+s = abc|abc|abc|abc; // 4abc
- s1 = a|bcabcabcab|c = bcabcabcab; // bc + 2*abc + ab

s1中依然包含s,则s是重复的字符串

```js
var repeatedSubstringPattern = function(s) {
    let s1 = (s + s).slice(1, -1);
    return s1.indexOf(s) != -1;
};
```

*法二：周期串*

周期串为s, 那么设定t表示最小周期, 数学中周期的表达式是

f(x+t)=f(x)

字符串中 ​s = item * count
​
那么我们需要找到最小周期 t = item.length

```js
var repeatedSubstringPattern = function(s) {
    let len = s.length;
    for (let t = 1; t <= len / 2; t++) {
        const item = s.slice(0, t);
        const count = len / item.count;
        if (Number.isInteger(count) && item.repeat(count) === s) {
            return true
        }
    }
    return false
};
```

或者

```js
var repeatedSubstringPattern = function(s) {
    let len = s.length;
    let i = 1;
    while(i <= len / 2) {
        if (len % i == 0 && s.slice(0, i).repeat(len/i) == s) {
            return true
        }
        i++;
    }
    return false
};
```

*法三:正则匹配*

```js
var repeatedSubstringPattern = function(s) {
    let reg = /^(\w+)\1+$/
    return reg.test(s)
};
```

`\1` 等于 `()` 中匹配的内容。

