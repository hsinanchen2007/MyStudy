### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
    if(!S.length)return S;
    function rmv(cache){
        let p0 = 0, l = cache.length;
        while(p0<l){
            if(cache[p0] == cache[p0+1]){
                cache.splice(p0, 2);
                l-=2;
                p0=0;
            }else{
                p0++;
            }
        }
    }
    const cache = [...S];
    rmv(cache);
    return cache.join('');
};
```