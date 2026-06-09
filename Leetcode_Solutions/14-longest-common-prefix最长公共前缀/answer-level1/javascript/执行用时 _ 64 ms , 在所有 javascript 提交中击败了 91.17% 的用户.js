思路很直接，
先处理掉数组长度是 0 和 1 的情况；
找到数组中最短的字符串，循环查找， indexOf 是 0 的情况，如果不是0 说明有不符合情况的字段， 返回上一次循环的结果即可
菜鸟一枚，仅能想到这种比较简单的逻辑思路了
执行效率出乎意料的好，果然还是越简单越好啊
```
    var longestCommonPrefix = function (strs) {
        if (strs.length === 0) return '';
        if (strs.length === 1) return strs[0];
        let k = strs[0];
        let r = '';
        let index = 0;

        for (let i = 0; i < strs.length; i++) {
            if (k.length > strs[i].length) {
                k = strs[i];
                index = strs[i];
            }
        }

        for (let j = 0; j < k.length; j++) {
            let t = k.substr(0, j + 1);
            for (let o = 0; o < strs.length; o++) {
                if (o === index) continue;
                if (strs[o].indexOf(t) === 0) {
                    r = t;
                } else {
                    r = r.substr(0, j);
                    return r;
                }
            }
        }

        return r;
    };
```
