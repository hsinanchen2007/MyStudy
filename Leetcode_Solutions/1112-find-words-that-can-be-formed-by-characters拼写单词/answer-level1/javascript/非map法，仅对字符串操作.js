### 解题思路
基本思路就是在 tmpStr 中寻找每个字母的位置
如果有就增加计数，并且在 tmpStr 中删除该字母

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let map={},lenI=words.length,count=0
    for(let i=0; i<lenI; i++){
        let tmpStr = chars      // 防止修改原字符串chars
        tmpCount = 0            // 记录本单词在chars中出现的次数
        for(let j=0; j<words[i].length; j++){
            let tmp = tmpStr.indexOf(words[i][j])   // 取words[i][j]在tmpStr中的位置
            if(tmp>-1){
                tmpCount++  // 如果取到计数+1
                tmpStr = tmpStr.substring(0,tmp)+tmpStr.substring(tmp+1,tmpStr.length)  // 在tmpStr中删除该字母
            }else{
                tmpCount=0  // 一旦有一个不存在的字母，计数器置零，并且跳出循环
                break
            }
        }
        count = count+tmpCount  
    }
    return count
};
```