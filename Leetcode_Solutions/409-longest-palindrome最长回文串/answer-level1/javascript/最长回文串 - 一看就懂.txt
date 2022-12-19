### 解题思路
一看就懂

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */


var longestPalindrome = function(s) {
    let o = {}, n = 0, m = 0
    for(let i=0; i<s.length; i++){
        if( !o[s[i]] ) o[s[i]] = 1
        else o[s[i]] += 1
    }
    n = Object.values(o).map(item=>{
        if(m==0 &&item % 2 > 0 ) m = 1 
        return parseInt(item/2) * 2
    }).reduce((a,b)=> a+b)
    n+=m
    return n
};

// 比解法二 ： 双循环 - 比解法三稍微快点
// var longestPalindrome = function(s) {
//     let o = {}, n = 0, m = 0
//     for(let i=0; i<s.length; i++){
//         if( !o[s[i]] ) o[s[i]] = 1
//         else o[s[i]] += 1
//     }
//     for(let key in o) {
//         n += parseInt(o[key]/2) * 2
//         m += o[key] % 2
//     }
//     if( m > 0) n++
//     return n
// };


// 解法三： em ...  暴力破解
// var longestPalindrome = function(s) {
//     let o = {}, n = 0;
//     for(let i=0; i<s.length; i++){
//         if( !o[s[i]] ) o[s[i]] = s[i] 
//         else {
//             n+=2
//             delete o[s[i]]
//         }
//     }
//     if(JSON.stringify(o) != "{}") n++
//     return n
// };
```