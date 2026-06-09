### 解题思路
1. 先对原字符串来一遍[20.有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)，并改成只把"("和")"对应原字符串**下标**入栈。一顿括号匹配后，剩下的就是无效括号的“根源”。此时栈的长度就是删除最小数量，栈中元素就是多余的括号位置。
2. 栈中元素满足以下规律：
    - ")"的位置绝对不会出现在"("的后面，即只有三种情况。
        - 全是")"。
        - 全是"("。
        - 左边x个")"右边y个"(" 如"))(("。
    - ")"对应的下标是所有可能无效的")"中最右边的，同样"("对应的下标是所有可能无效的"("中最左边的。
    - 若有栈中多个"(",")"的下标,"("中最小下标左边的括号字串必定是有效括号，"("中最大下标右边的括号字串必定也是有效括号，并且删除字串中任何的"("或")"都可以和栈中的"("或")"组成有效括号。例如"()())",最右边的无效括号下标是4,那么删除1,3,4的")"都可以形成有效括号字符串。当然删除3和4得到的字符串是一样的，加个set去重就OK了

把规律写入BFS中就完事了...（表面两次BSF，实际上是把"("和")"分别处理。")"逆序遍历，"("顺序遍历，还能减点枝）
### javascript

```javascript
/**
 * @param {string} s
 * @return {string[]}
 */
var removeInvalidParentheses = function(s) {
    let index=[],str=[],arr=[s],se=new Set();
    for(let i=0;i<s.length;i++){
        if(s[i]==")"&&index.length&&s[index[index.length-1]]=="(") index.pop()
        else if(s[i]=="("||s[i]==")") index.push(i)
    }
    while(index.length){
        if(s[index[index.length-1]]==")") break;
        let a=[],b=index.pop();
        for(let j of arr){
            for(let i=b;i<j.length;i++){
                if(j[i]=="("){
                    let string_=j.slice(0,i)+j.slice(i+1)
                    if(!se.has(string_)){
                        se.add(string_);
                        a.push(string_)
                    }
                }
            }
        }
        arr=a; 
    }
    for(let k=0;k<index.length;k++){
        let a=[];
        for(let j of arr){
            for(let i=0;i<=index[k]-k;i++){
                if(j[i]==")"){
                    let string_=j.slice(0,i)+j.slice(i+1)
                    if(!se.has(string_)){
                        se.add(string_);
                        a.push(string_)
                    }
                }
            }
        }
        arr=a; 
    }
    return arr;
};
```