### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    const arr=[];
    for(let a of address){
        if(a=='.')arr.push('[',a,']');
        else arr.push(a);
    }
    return arr.join('');
};
```