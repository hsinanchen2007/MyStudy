### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    // let res = '';
    // let cur = '';
    // if(strs.length < 1){
    //   return res;
    // }
    // else if(strs.length === 1){
    //     return strs[0];
    // }else {
    //     for(let j =0; j< strs[0].length;j++){
    //         cur = strs[0].slice(j,j+1);
    //         for(let i=0;i<strs.length;i++){
    //             if(strs[i].charAt(j) !== cur){
    //                 return res;
    //             }
    //         }
    //         res += cur;
    //     }
    //     return res;
    // }
    if(!strs.length){
        return '';
    }
    let charTestFunc = index => {
        const firstChar = strs[0].charAt(index);
        if(!firstChar){
            return '';
        };
        for(let i=1;i< strs.length;i++){
            if(strs[i].charAt(index) !== firstChar){
                return '';
            }
        }
        return firstChar + charTestFunc(index +1);
    };
    return charTestFunc(0);
};
```