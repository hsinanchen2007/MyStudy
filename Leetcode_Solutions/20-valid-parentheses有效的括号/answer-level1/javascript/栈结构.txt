### 解题思路
看到这个题目就想起大学数据结构老师教的计算器的匹配算法
用栈结构可以很方便的解决。。提交失败三次的原因是把一个==写错了 写成了!= 我的妈呀

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if(s.length<=0){
        return true;
    }
    if(s.length%2!=0){
        return false;
    }
    let stash = [];
    for(let i in s){
        if(s[i] == '(' || s[i] =='[' || s[i] =='{'){
            stash.push(s[i]);
        }
        else{
            switch (s[i]){
                case ')':
                    if(stash[stash.length-1] == '('){
                        stash.pop();
                    }
                    break;
                case ']':
                    if(stash[stash.length-1] == '['){
                        stash.pop();
                    }
                    break;
                case '}':
                    if(stash[stash.length-1] == '{'){
                        stash.pop();
                    }
                    break;
            }
        }
    }
    return stash.length==0;
};
```