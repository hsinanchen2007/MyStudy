### 解题思路
![image.png](https://pic.leetcode-cn.com/2b03ff473acb6cec6dc74c1ab242adfd0c9d4b494208a359c478a8587522f51a-image.png)
利用变量： 遍历增加 substr ，如遇相同字符，则按相同字符下标截取。 并记录最大长度
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */

/**
 * 解法二：  
 *      利用变量： 遍历增加 substr ，如遇相同字符，则按相同字符下标截取。 并记录最大长度
 */
var lengthOfLongestSubstring = function(s) {
    let substr = '', maxlen = 0;
    for( let i=0;i<s.length; i++){
        const index = substr.indexOf(s[i])
        if( ~index ) substr = substr.substring( index + 1 )
        substr += s[i]
        if(substr.length > maxlen) maxlen = substr.length
    }
    return maxlen
};

/**
 * 解法一： 暴力超时..
 */
// var lengthOfLongestSubstring = function(s) {
//     let str = ''
//     for( let i=0,len=s.length; i<len; i++){
//         for( let j = i+1, _len=s.length+1; j<_len;j++){
//             let temp = s.substring(i,j)
//             if( temp.split('').filter((item,index,self)=> self.indexOf(item) ==index ).join('') == temp && temp.length > str.length ){
//                 str = temp
//             }
//         }
//     }
//     return str.length
// };
```