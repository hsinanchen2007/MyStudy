### 解题思路
方法一、indexOf函数

### 代码

```javascript
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    var arr = str.split(' ');
    if(pattern.length!=arr.length) return false;
    for(var i=0;i<pattern.length;i++){
        if(pattern.indexOf(pattern[i])!=arr.indexOf(arr[i])){
            return false;
        }
    }
    return true;
};
```
方法二、哈希map
```
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    var arr = str.split(' ');
    var map = new Map();
    var maps = new Map();
    if(pattern.length!=arr.length) return false;
    for(var i=0;i<pattern.length;i++){
        
        if(maps.has(arr[i])==false){
            maps.set(arr[i],pattern[i]);
        }else{
            if(maps.get(arr[i])!=pattern[i]){
                return false
            }
        }
        if(map.has(pattern[i])==false){
            map.set(pattern[i],arr[i]);
        }else{
            if(map.get(pattern[i])!=arr[i]){
                return false
            }
        }

    }
    return true;
};
```
