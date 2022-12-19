### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
    if (envelopes.length === 0) {
        return 0;
    }
    // [w,h] w升序, h降序 二维转一维,再寻找h的最长升序子序列
    envelopes.sort(([pW, pH],[nW, nH]) => {
        if (pW > nW) {
            return 1;
        } else if (pW < nW) {
            return -1;
        } else if (pH > nH){
            return -1;
        } else if (pH < nH) {
            return  1;
        }
    });
    hArr = envelopes.map(([w,h]) => h);
    let len = 1;
    let maxArr = [hArr[0]];
    for (let i=1; i<hArr.length;i++) {
        let h = hArr[i];
        let maxLast = maxArr[maxArr.length-1];
        if (h > maxLast) {
            len++;
            maxArr.push(h);
        } else if (h < maxLast) {
            for (let j = 0; j < maxArr.length; j++) {
                if (h <= maxArr[j]) {
                    maxArr[j] = h;
                    break;
                }
            }
        }
    }
    return len;
};
```