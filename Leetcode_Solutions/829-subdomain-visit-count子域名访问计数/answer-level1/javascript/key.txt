### 解题思路
先将地址转化为键名 将访问次数作为键值
如果重复直接加在键值上
最后遍历 用模板字符串生成所需格式
### 代码

```javascript
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function (cpdomains) {
    let obj = {}
    cpdomains.forEach((item) => {
        let count = +item.split(" ")[0];
        let str = item.split(" ")[1];
        obj[str] = obj[str] ? obj[str] + count : count
        while (str.indexOf('.') > -1) {
            str = str.substr(str.indexOf('.') + 1)
            obj[str] = obj[str] ? obj[str] + count : count
        }
    })
    let list = [];
    for(var key in obj){
        list.push(`${obj[key]} ${key}`)
    }
    return list
};
```