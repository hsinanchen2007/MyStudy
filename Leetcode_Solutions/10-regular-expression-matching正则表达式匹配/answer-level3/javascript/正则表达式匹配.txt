### 解题思路
用递归

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
let isMatch = (s,p)=>{
    //边界问题如果s和p都为空,满足
    if(p.length<=0){
        return !s.length
    }
    let match = false
    //判断第一个字符是否匹配,首先保证s不能为空，否则无法匹配，然后开始比较s和p的第一个字符，如果p[0]是‘.’，代表匹配所有字符，也满足
    if(s.length>0&&(p[0]===s[0]||p[0]==='.')){
        match = true
    }
    //p带模式
    if(p.length>1&&p[1]==='*'){
        //两种情况
        //第一种p*为0
        //第二种p*为多个
        return isMatch(s,p.slice(2)) || (match&&isMatch(s.slice(1),p))
    }else {
        return match&&isMatch(s.slice(1),p.slice(1))
    }
};

```