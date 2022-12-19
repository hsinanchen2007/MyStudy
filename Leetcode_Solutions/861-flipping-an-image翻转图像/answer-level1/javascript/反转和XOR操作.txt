### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    return A.map(a=>a.reverse()).map(eles=>{
        const neles = [];
        for(let e of eles){
            e^=1;
            neles.push(e);
        }
        return neles;
    });
};
```