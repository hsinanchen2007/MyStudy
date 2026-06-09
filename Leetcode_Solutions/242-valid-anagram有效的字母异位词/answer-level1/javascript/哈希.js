### 解题思路
哈希map

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length!=t.length) return false;
    var maps = new Map();
    for(var str of s){
        if(maps.has(str)){
            maps.set(str,maps.get(str)+1);
        }else{
            maps.set(str,1);
        }
    }
    for(var n of t){
        if(maps.has(n)&&maps.get(n)>0){
            maps.set(n,maps.get(n)-1);
        }
        else{
            return false;
        }
    }
    return true;
};


```