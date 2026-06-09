### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    if(ransomNote.length>magazine.length){
        return false
    }
    var map = new Map()
    for(var i=0;i<ransomNote.length;i++){
        if(map.has(ransomNote[i])){
            map.set(ransomNote[i],map.get(ransomNote[i])+1)
        }else{
            map.set(ransomNote[i],1)
        }
    }
    for(var j=0;j<magazine.length;j++){
        if(map.has(magazine[j])){
            map.set(magazine[j],map.get(magazine[j])-1)
        }
    }
    for(i=0;i<ransomNote.length;i++){
        if(map.get(ransomNote[i])>0){
            return false
        }
    }
    return true;
};
```