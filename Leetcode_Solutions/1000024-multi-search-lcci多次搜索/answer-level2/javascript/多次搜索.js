### 解题思路

利用 `indexOf` 去一次在 `big` 中查找是否存在查询的字符串。

### 代码

```javascript
/**
 * @param {string} big
 * @param {string[]} smalls
 * @return {number[][]}
 */
var multiSearch = function(big, smalls) {
    let result = [];
    const getAllIndex = (str) => {
        if(!str) return [];
        let i = 0, result = [];
        while(i < big.length){
            let index = big.indexOf(str, i);
            if(index === -1) break;
            else {
                result.push(index);
                i = index + 1;
            }
        }
        return result;
    }
    for(let i of smalls){
        result.push(getAllIndex(i));
    }
    return result;
};
```