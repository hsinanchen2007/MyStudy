### 解题思路
我把能返回false的情况分为两种  1 对称 2开阔号紧跟着闭括号
定义了一个变量 储存所有括号 按开阔号 闭括号 形式
判断s是奇数直接false
循环数组 如果开阔号紧跟着闭括号 就从s中移除
循环完后得到只有两种可能1 对称 2 不对称
再一次循环 根据定义的str变量 各取首尾 判断

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let str = "{}[]()";
    if (s.length=0) return false;
    if(parseInt((1+s.length)/2)!=parseInt(s.length)/2) return false;
    for(let i =0;i<s.length-1;i++){
        if(str.indexOf(s[i]) <0) return false
        if(str.indexOf(s[i])+1 == str.indexOf(s[i+1])){
            s=s.substring(0,i)+s.substring(i+2)
            i=-1
            if(s.length = 0) return true
        }
    }
    for(let i =0;i< parseInt(s.length/2);i++){
        if(str.indexOf(s[i]) +1 !==  str.indexOf(s[s.length-1-i])){
            return false
        }
    }
    return true
};
```