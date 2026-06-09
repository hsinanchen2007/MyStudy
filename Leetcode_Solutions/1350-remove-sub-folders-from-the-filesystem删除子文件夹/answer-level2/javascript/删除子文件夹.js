### 解题思路

1、将 `folder` 按字典序进行排序；
2、依次去对比每一项。

### 代码

```javascript
/**
 * @param {string[]} folder
 * @return {string[]}
 */
var removeSubfolders = function(folder) {
    folder = folder.sort();
    let result = [];
    const { length } = folder;
    for(let i = 0,j; i < length; i++){
        j = i + 1;
        let v = `${folder[i]}/`;
        result.push(folder[i]);
        while(j < length){
            if(!folder[j].includes(v)) break;
            j++;
        }
        i = j - 1;
    }
    return result;
};
```