![1566631857(1).jpg](https://pic.leetcode-cn.com/08a2a17c8f0c98db351f93a6d1c1320b106b14b3b1a47d72de9e533a3cfa40aa-1566631857\(1\).jpg)


熟悉一下map结构
```
var isIsomorphic = function(s, t) {
    var map = new Map
    for (let i = 0; i < s.length; i++) {
        if (map.has(s[i])) {
            if (map.get(s[i]) === t[i]) {
                continue
            } else {
                return false
            }
        }
        if (Array.from(map.values()).indexOf(t[i]) !== -1) return false
        map.set(s[i],t[i])
    }
    return true
};
```
