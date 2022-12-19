### 解题思路
重点在于如何找出最外层的括号
很重要的思路在于+1，和-1给括号做标识
计数器count 在1和0的时候必定产生括号闭合或者新的左括号，同时0和1不能分辨是否是内部括号，因此我加了额外判断条件
由于splice方法是变异方法，没办法多次调用删除多个下标，每次都会变
因此直接选择“非”思路，把不用删除的元素推到输出的数组里（其实是懒得写非的判断，感觉有点绕）

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    if(S==''){
        return '';
    }
    let myString = S.split("");
    let newString = []
    let count = 0;
    for(let i = 0;i<S.length;i++){
        if(S[i]=='('){
            ++count;
        }else{
            --count;
        }
        if(count==0&&S[i]==')'||count==1&&S[i]=='('){
          
        }else{
            newString.push(S[i]);
        }
    }
    return newString.join('');
};
```