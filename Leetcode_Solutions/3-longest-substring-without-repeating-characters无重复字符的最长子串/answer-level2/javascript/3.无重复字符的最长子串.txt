### 解题思路
使用到字符串方法indexOf()查找字符串，如果找到返回字符串的索引值，找不到则返回-1；
push()尾部进入队列；
shift()头部移除
continue跳过当前循环
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var result=0;
    var i=0;
    var temp =[];
    while(i<s.length){
        if(temp.indexOf(s[i])===-1){//找不到匹配的字符串将该字符压入队列中
            temp.push(s[i]);
        }else{
            temp.shift();   //找到匹配的字符串，从头部移除一个，直至将与该字符匹配的字符移除队列
            continue;
        }
        result=Math.max(result,temp.length);
        i++;
    }
    return result;
}
```