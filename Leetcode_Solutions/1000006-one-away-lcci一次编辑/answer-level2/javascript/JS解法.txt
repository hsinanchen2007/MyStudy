### 解题思路
首先判断两个字符串是否相同，相同返回true；
不同则分为两种情况：
1.长度相同，判断两个字符串对位是否相同，记录不同次数，次数小于等于1则返回true；
2.长度差一位，先用循环找出长字符串和短字符串开始出现不同的位置，在长字符串中截取不包括该位置的后面部分与短字符串包括该位置的后面部分进行比较，相同返回true。

### 代码

```javascript
/**
 * @param {string} first
 * @param {string} second
 * @return {boolean}
 */
var oneEditAway = function(first, second) {
    if(first===second){return true}
    let a=first.length;
    let b=second.length;
    if(a===b){
        let c=0;
        for(let i=0;i<a;i++){
            if(first[i]!==second[i]){
                c++
            }
        }
        return c<=1
    }else if(a-b===1||-1){
        let s1=a>b?first:second;
        let s2=a<b?first:second;
        for(let i=0;i<s1.length;i++){
            if(s1[i]!==s2[i]){
                return s1.substring(i+1)===s2.substring(i)
            }
        }
    }
    return false
};
```