### 解题思路
题意：能不能用杂志中的字符拼成信中的

### 代码

```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    //ransomNote是margazine的子集
    for(var i = 0;i<ransomNote.length;i++){
        var index = magazine.indexOf(ransomNote[i])
        if( index ===-1){
            return false;
        }else{
           magazine =  magazine.substring(0,index) + magazine.substring(index+1,magazine.length)
           
        }
    }
    return true
};
```