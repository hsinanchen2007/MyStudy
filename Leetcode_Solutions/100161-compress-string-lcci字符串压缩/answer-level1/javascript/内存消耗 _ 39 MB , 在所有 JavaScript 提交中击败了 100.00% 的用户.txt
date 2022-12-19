### 解题思路
此处撰写解题思路
首先声明一个空字符str和计算次数count；假设样本为S[0]，遍历S，相同的时候count++；不相同时拼接字符str,样本改为S[i],count赋值为1；最后比较长度就可以了。
### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let count=0;
    let first=S[0];
    let str='';
    for(let i=0;i<=S.length;++i){
        if(S[i]==first){
            count++;
        }else{
            str+=first+count;
            first=S[i];
            count=1;
        }
    }
    return S.length>str.length?str:S;
};
```