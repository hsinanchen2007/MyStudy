
```javascript
var findDuplicate = function(paths) {
    const contentMap = {}
    const reg = /^([0-9a-zA-Z]+\.txt)\((\w+)\)$/
    paths.forEach(item=>{
        const itemSplit = item.split(' ')
        const dir = itemSplit[0]
        itemSplit.slice(1).forEach(file=>{
            const [a,name,content] = file.match(reg)
            if(contentMap[content]) contentMap[content].push(`${dir}/${name}`)
            else contentMap[content] = [`${dir}/${name}`]
        })
    })
    const result = []
    for(const item in contentMap){
        if(contentMap[item].length > 1)result.push(contentMap[item])
    }
    return result
};
```
执行用时 :152 ms , 在所有 JavaScript 提交中击败了 94.74% 的用户
内存消耗 :58.2 MB, 在所有 JavaScript 提交中击败了 88.89% 的用户