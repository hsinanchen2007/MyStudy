### 解题思路
此处撰写解题思路
两个字符串 所含字母完全相同,且所含字母个数相同
### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length !== t.length ) return false
    // 两个字符串 所含字母完全相同
    const sArr = s.split('')
    const tArr = t.split('')
    const sObj ={} 
    const tObj={} 
    for(let i = 0;i<sArr.length;i++){
        if(sObj[sArr[i]]){
           sObj[sArr[i]]++ 
        }else{
            sObj[sArr[i]] = 1
        }
           if(tObj[tArr[i]]){
           tObj[tArr[i]]++ 
        }else{
            tObj[tArr[i]] = 1
        }
        
    }
    const keyArr = Object.keys(sObj)
    for(let j =0;j<keyArr.length;j++){
        if(sObj[keyArr[j]] !== tObj[keyArr[j]]){
            return false
        }
    }
    return true

};
```