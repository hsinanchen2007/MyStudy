### 解题思路
方法一、map

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    var map1=new Map();
    var map2=new Map();
    for(var i=0;i<s.length;i++){
        if(map1.has(s[i])){
            map1.set(s[i],map1.get(s[i])+1)
        }else{
            map1.set(s[i],1)
        }
    }
    for(var i=0;i<t.length;i++){
        if(map2.has(t[i])){
            map2.set(t[i],map2.get(t[i])+1)
        }else{
            map2.set(t[i],1)
        }
    }
    for(var i=0;i<t.length;i++){
        if(map1.has(t[i])){
            if(map1.get(t[i])!=map2.get(t[i])){
                return t[i]
            }
        }else{
            return t[i];
        }
    }
};
```
方法二、ascii码之和相减就是插入的字符
```
var findTheDifference = function(s, t) {
    var ascii1=0;
    var ascii2=0;
    for(var i=0;i<s.length;i++){
        ascii1 += s[i].charCodeAt();
    }
    for(var i=0;i<t.length;i++){
        ascii2 += t[i].charCodeAt();
    }
    return String.fromCharCode(ascii2-ascii1);
};
```
