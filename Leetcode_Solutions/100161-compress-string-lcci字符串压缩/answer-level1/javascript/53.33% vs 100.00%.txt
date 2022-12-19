### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if(!S) return '';

    let res = '';
    let count = 1;
    let arrS = S.split('');

    for(let i=0, len=arrS.length; i<len; i++) {
        if(arrS[i] !== arrS[i+1]) {
            res = res + arrS[i] + count;
            count = 1;
        }else {
            count += 1;
        }
    }
    return S.length > res.length ? res : S;

};
```