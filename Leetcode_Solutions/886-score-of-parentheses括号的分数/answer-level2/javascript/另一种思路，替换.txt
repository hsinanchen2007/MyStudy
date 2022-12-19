 1. 先将所有() 替换为#1#
 2. 将(#x#)替换为#2*x#
 3. 将#x##y#替换为#x+y#
 4. 不停重复2,3 直到无法替换 得到#x#
 5. 得到x返回
```
代码块
/**
 * @param {string} S
 * @return {number}
 */
var scoreOfParentheses = function (S) {
    let s1 = S.replace(/\(\)/g, "#1#");
    let s = s1
    while (true) {
        s = replace1(s1);
        //console.log("xxxx",s)
        s = replace2(s);
        // console.log("yyyy",s)
        if (s.length != s1.length) {
            s1 = s;
        } else {
            break;
        }
    }
    return parseInt(s1.replace("#", ""));
};
function replace1(s) {
    return s.replace(/\(#(\d+)#\)/g, (all, re1) => {
        // console.log("11111",all,re1)
        return "#" + 2 * re1 + "#"
    })
}
function replace2(s) {
    return s.replace(/#(\d+)##(\d+)#/g, (all, re1, re2) => {
        // console.log("2222",all,re1,re2)
        return "#" + (+re1 + +re2) + "#";
    })
}
```

