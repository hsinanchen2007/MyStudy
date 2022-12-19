### 解题思路
为了去重、提高查询、删除效率，用Set对象将words的内容存储起来，找出每个单词的所有后缀去Set中寻找是否有一样的，有的话就删除。最后统计Set中所有值的长度和

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    let wordsSet = new Set(words);
    let result=0;
    wordsSet.forEach(value=>{
        for(let i=1;i<value.length;i++){
            let tmp = value.slice(i);
            if(wordsSet.has(tmp)){
                wordsSet.delete(tmp);
            }
        }        
    });
    wordsSet.forEach(value=>{
        result += value.length+1;
    });
    return result;
};
```