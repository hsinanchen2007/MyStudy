### 解题思路
遍历chars，将每个字符和它出现的次数分别作为key-value保存
遍历words，对每个单词进行遍历，使用已经生成的hash来检测某个字符出现的次数

### 代码

```javascript
var countCharacters = function(words, chars) {
    let needs = new Map(), res = 0;

    for (let n of chars) {
        needs.set(n, needs.has(n) ? needs.get(n) + 1 : 1);
    }

    for (let s of words) {
        if (help(s, new Map(needs))) {
            res += s.length;
        }
    }
    return res;
};

function help(s, hash) {
    for (let n of s) {
        if (!hash.has(n)) {
            return false;
        } else {
            hash.set(n, hash.get(n) - 1);
            if (hash.get(n) < 0) return false;
        }
    }
    return true;
}
```