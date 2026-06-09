### 解题思路
这题当时在字母的ASCII代码上纠结排序，其实原生即可。 80ms超过90%左右。
1. 统计词频：js的Object自带key、value对应；类似Map；
2. key排序；kv映射；
3. 遍历集合筛选；

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */
var topKFrequent = function(words, k) {
    var obj = {}, arr = []
    for(var i=0; i<words.length; i++){
        if(obj[words[i]]){
            obj[words[i]]++
        } else {
            obj[words[i]] = 1
        }
    }
    let keys = Object.keys(obj).sort((a,b)=>obj[b]-obj[a])
    let vals = keys.map(m => obj[m])
    new Set(vals).forEach(m => {
        let mr = keys.filter(n=>m=== obj[n])
        if(mr.length > 1) mr.sort()
        arr = arr.concat(mr)
    })
    return arr.slice(0, k)
};
```