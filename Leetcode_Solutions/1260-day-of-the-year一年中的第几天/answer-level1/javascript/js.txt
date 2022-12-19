### 解题思路
此处撰写解题思路
知识点总结：
     日期转时间戳   +new Date("2019-01-01")
                  new Date('2019-01-01').getTime()
                  new Date('2019-01-01').valueOf()
      +1天的原因是，例如9号，实际才真正过去8天整天，当9*24*3600时下一秒已经是10号了
    
      slice(start, end) 方法可提取字符串的某个部分，并以新的字符串返回被提取的部分
   
### 代码

```javascript
/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function(date) {
    var first = date.slice(0,4)+'-01-01'
    console.log(+new Date(date))
    console.log(+new Date(first))
    return ((+new Date(date))-(+new Date(first)))/(24*60*60*1000)+1

};
```