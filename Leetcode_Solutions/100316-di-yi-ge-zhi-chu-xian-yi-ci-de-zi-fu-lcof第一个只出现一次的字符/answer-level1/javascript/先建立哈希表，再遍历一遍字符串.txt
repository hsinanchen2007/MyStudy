### 解题思路
先建立哈希表，再遍历一遍字符串
时间复杂度: O(N)
空间复杂度度: O(N)，因为建立了哈希表
### 代码

```javascript
var firstUniqChar = function(s) {
    // 先建立哈希表，再遍历一遍字符串
    let map = new Map();
    for(let i = 0; i < s.length; i++){
        if (map.has(s[i])){
            map.set(s[i], map.get(s[i])+1);
        }else{
            map.set(s[i], 1);
        }
    }
    
    for(let i = 0; i < s.length; i++){
        if (map.get(s[i]) === 1){
            return s[i];
        }
    }
    return " ";
};
```