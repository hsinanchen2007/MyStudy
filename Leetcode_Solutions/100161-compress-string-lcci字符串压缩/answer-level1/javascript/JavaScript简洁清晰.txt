**思路**
1、判断S[i]是否等于S[i+1]
2、是的话计数+1
3、不是的话添加到结果中并重置计数

**代码**
```
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let count = 1;
    let s = '';
    for(let i = 0; i <S.length; i++) {
        if(S[i] === S[i + 1]) {
            count += 1;
        } else {
            s = s.concat(S[i], count);
            count = 1;
        }
    }
    return s.length < S.length ? s : S;
};
```
