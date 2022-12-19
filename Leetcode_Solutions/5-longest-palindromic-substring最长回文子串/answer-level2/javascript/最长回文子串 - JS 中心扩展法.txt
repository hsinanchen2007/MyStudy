### 解题思路
中心扩展法, 根据回文数的特性： 对称结构。
有两种情况   aba  ||  aa

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
/**
 * 中心扩展法：
 */
var longestPalindrome = function(s) {
    if ( s.length < 2) return s;
    let str = '';
    for( let i = 0; i < s.length; i++){
        const str1 = getStr(s, i,i)
        const str2 = getStr(s, i,i+1)
        if( str1.length > str.length || str2.length > str.length ){
            str = str1.length > str2.length ? str1 : str2
        }
    }
	return str
}
var getStr = ( s, i , j) => {
	if( s[i] != s[j] ) return ''
    let L = i , R = j ;
    while( L > 0 && R < s.length && s[L-1] == s[R+1] ){
        L--;
        R++;
    }
    return s.substring(L,R+1)
}


/**
 * 解法一：
 * 暴力超时 1000个字符串... 
 */
// var longestPalindrome = function(s) {
//     let str = ''
//     for( let i=0; i < s.length ; i++){
//         let j = 1
//         while( j<=s.length ){
//             const subS = s.substring(i,j)
//             if( isPalindrome( subS ) && subS.length > str.length){
//                 str = subS
//             }
//             j++
//         }
//     }
//     return str
// };
// var isPalindrome = function(x) {
//     if( x < 0 ) return false
//     x = String(x)
//     for(let i=0,len=x.length; i<len/2; i++){
//         if( x[i] != x[len - i -1]) return false
//     }
//     return true
// };
```