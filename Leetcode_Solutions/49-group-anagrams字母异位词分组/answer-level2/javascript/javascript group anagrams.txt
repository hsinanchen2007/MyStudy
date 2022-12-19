主要是ascci码的使用


```
var groupAnagrams = function(strs) {
    if(strs.length === 0) {
        return []
    }
    let map = new Map();
    for(const str of strs) {
        let character = Array(26).fill(0)
        for(let i=0; i<str.length; i++){
            let ascci = str.charCodeAt(i) - 97;
            character[ascci] ++
        }
        var key = character.join("");
        if(map.has(key)){
            map.set(key, [...map.get(key), str])
        } else {
            map.set(key, [str])
        }
    }

    const result = []
    for(const ele of map) {
        result.push(ele[1])
    }
    return result
};
```
