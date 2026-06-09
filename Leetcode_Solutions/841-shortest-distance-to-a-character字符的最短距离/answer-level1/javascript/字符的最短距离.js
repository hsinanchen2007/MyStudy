*法一：双循环*

```js
var shortestToChar = function(S, C) {
    let len = S.length;
    // 存储C出现在S中的index
    let cArr = [];
    let res = [];
    for (let i = 0; i < len; i++) {
        if (S[i] === C) {
            cArr.push(i)
        }
    }
    for (let i = 0; i < len; i++) {
        let distance = Math.abs(i - cArr[0]);
        for (let j = 0; j < cArr.length; j++) {
            if (distance > Math.abs(i - cArr[j])) {
                distance = Math.abs(i - cArr[j])
            }
        }
        res.push(distance)
    }
    return res;
};
```

*法二： 双指针*

```js
var shortestToChar2 = function(S, C) {
    let len = S.length;
    let res = [];
    // 先找到前两个 C 出现的位置
    let left = S.indexOf(C);
    let right = S.indexOf(C, 1 + left);
    for (let i = 0; i < len; i++) {
        // 计算与左指针的距离
        res[i] = Math.abs(left - i);
        if (right != -1) {
            // 如果右指针存在,取较小的距离
            res[i] = Math.min(res[i], right - i) 
            // i 走到右指针则左右指针往下一个
            if (i == right) {
                res[i] = 0;
                left = right;
                right = S.indexOf(C, right + 1)
            }
        }
    }
    return res;
};
```

此题用双指针没有双循环快