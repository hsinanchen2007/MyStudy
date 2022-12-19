### 解题思路

用一次循环建一个对象obj存储chars中的字母和每个字母对应的数量。遍历words中的每个单词进行比对。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let obj={};
    let result="";
    for(let i=0;i<chars.length;i++){
        obj[chars[i]]?obj[chars[i]]++:obj[chars[i]]=1
    }
    for(let i=0;i<words.length;i++){
        //单词长度大于chars长度时直接continue
        if(words[i].length>chars.length)continue;
        let flag = true;
        //深拷贝一份obj
        let obj2 = JSON.parse(JSON.stringify(obj));        
        for(let j=0;j<words[i].length;j++){
            if(obj2[words[i][j]]){
                obj2[words[i][j]]-=1;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            result += words[i];
        }
    }
    return result.length;
};
```