### 解题思路
![image.png](https://pic.leetcode-cn.com/ba0d8a6f6cf257e6532d8ebbff9cf490bef2a491c8e81298e2b7f79263817826-image.png)

开始简单粗暴的解决，但没想到这压缩编码是用全局压缩，开始读题以为只可能是向后压缩，即只有后面出现的词语，只能用前面已出现过的，而不能反着来，结果下面这个输入让我直接挂掉：
```js
["me", "time"]
```

但仔细一审题，发现只需要给出压缩后的长度，并没有要求给出索引，这，那就可以投机取巧了；排个序就的了呗，顺便Set再去个重；

所以思路就是：
 - Set 去重
 - sort 排序，长单词在前
 - indexOf 查找重复

但有个细节需要注意就是重复不能从中间去找，而只能从尾部去匹配, 这里有个技巧：
```js
’time‘.index('me') = 2;
’time‘.index('im') = 1; // 但以题目的意思，im是不会被匹配到的；

’time#‘.index('me#') = 2; // 正常匹配到
’time#‘.index('im#') = -1; // 加#，就可以完美避免从中间匹配到；
```
### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    if (words.length < 2) {
        return words.length ? words[0].length + 1 : 0;
    }
    let i = 1;
    words = [...new Set(words)]; // 去重；
    words.sort((a, b) => b.length - a.length); // 排序
    let res = `${words[0]}#`;
    // let index = 0;
    // let indexs = [index];
    while (i < words.length) {
        const target = `${words[i]}#`;
        const start = res.indexOf(target);
        if (start < 0) {
            // index = res.length;
            // indexs.push(index);
            res += target;
        }
        i++;
    }
    // console.log('index', res, indexs);
    return res.length;
};
```