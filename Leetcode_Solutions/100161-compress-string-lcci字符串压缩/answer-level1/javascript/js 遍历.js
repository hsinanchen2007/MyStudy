### 解题思路
 
 遍历，temp暂存，一致num++ 否则组建输出字符串，temp指向新的char

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let res = '';
    let temp = '';
    let num = 0;
    for(let i = 0; i < S.length; i ++) {
        if(temp === S.charAt(i)) {
            num++;
        } else {
            if(num > 0)
                res +=  temp + num
            temp = S.charAt(i);
            num = 1;
        }
    }

    res += temp + num;
    if(S.length > res.length){
        return res;
    } else {
        return S;
    }
};
```