### 解题思路
思路是先去重（set结构），然后把每个单词循环截取，
查找截取的部分是否存在在数组里，有则删除，最后算长度。
题目有个隐藏信息，读取以#结束，就是只需要向后截取即可（考虑后缀，不用考虑前缀和在中间的情况）。

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    let arr=new Set(words);
    for(let i of arr){
       for(let j=1;j<i.length;j++){
           arr.has(i.slice(j))&&arr.delete(i.slice(j))
       }
    }
    return [...arr].reduce((a,b)=>a+b.length+1,0)
};
```