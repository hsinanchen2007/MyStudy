```
var isIsomorphic = function(s, t) {
        //s和t具有相同的长度，对照着比较就OK
        // egg
        // add
        let map1 = new Map();
        let map2  = new Map();  //判断是否存在两个字符映射到同一个字符上
        for(let i=0;i<t.length;++i){
            if(!map1.has(t[i])){
                if(!map2.has(s[i])){
                    map2.set(s[i],t[i]);
                    map1.set(t[i],s[i]);
                } else return false;
            } else {
                if(map2.get(s[i])!==t[i]) return false;
            }
        }
        return true;
};
```
