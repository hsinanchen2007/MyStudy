### 解题思路
第一种方法：
首先判断字符串长度为零的情况；
设一个空字符串和一个初始值为1的数纪录重复个数；
循环比较与下一个是否相同，相同记录数+1，不同就拼入新的字符串里，并还原记录数。

第二种方法（搬运）：利用双指针（快慢指针）算法思想。

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if(!S){return S}
    let str="";
    let n=1;
    for(let i=0;i<S.length;i++){
        if(S[i]===S[i+1]){
            n++
        }else{
            str+=S[i]+n;
            n=1
        }
    }
    return str.length<S.length?str:S


    let str="",a=b=0;
    while(a<=S.length){
        if(S[a]!==S[a+1]){
            str+=S[a]+(a-b+1)
            b=a+1
        }
        a++
    }
    return str.length<S.length?str:S
};
```