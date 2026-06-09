### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    let map = new Map()
    let ret = []
    for(let item of cpdomains)
    {
        [num,url] = item.split(' ')
        let arr = url.split('.')
        let i = arr.length -1
        let str = arr[i]
        while(i >= 0)
        {
            if(map.has(str))
            {
                map.set(str,Number(map.get(str)) + Number(num))
            }
            else
            {
                map.set(str,Number(num))
            }
            str =  arr[--i] + '.' + str
        }
    }

    map.forEach((value,key)=>{
        ret.push(value + ' ' + key)
    })
    return ret
};
```