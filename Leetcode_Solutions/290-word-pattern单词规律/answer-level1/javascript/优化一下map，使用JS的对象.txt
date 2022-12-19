### 解题思路
利用对象{}存储正向反向的对应关系，存在正向关系并且当前word不满足 或者 不存在正向关系但存在反向关系时return false

### 代码

```javascript
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    const obj = {},arr = str.split(' '),n = arr.length;
    if(pattern.length !== n) return false;
    for(let i = 0;i<n;i++){
        if(obj[pattern[i]]){
            if(obj[pattern[i]] !== arr[i]){
                return false
            }
        }else if(obj['_'+arr[i]]){
            return false
        }else { 
            obj[pattern[i]] = arr[i]
            obj['_'+arr[i]] = pattern[i]
        }
    }
    return true
};
```