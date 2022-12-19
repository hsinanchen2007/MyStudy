```javascript []
// 思路 
// （ 左括号入栈 ）又括号出栈 
// 这样当栈的数据被清零时 清除的数据中就包含了一个原语 
// 只需把起始的左括号和终点的又括号去除就得到了原语
// 举个例子 (()())(())

（ 进栈  此时栈：(    // 起始位置
 ( 进栈  此时栈：((
 ) 出栈  此时栈：(
 ( 进栈  此时栈：((
 ) 出栈  此时栈：(
 ) 出栈  此时栈：空   // 终止位置
（ 进栈  此时栈：(   // 起始位置
 ( 进栈  此时栈：((
 ) 出栈  此时栈：(
 ) 出栈  此时栈：空  // 终止位置

// 实现一个栈 后入先出
        class Stack{
            arr = []
            constructor(){
                this.arr = []
            }
            // 向栈添加数据
            add=(data)=>{
                this.arr.push(data)
            }
            // 出栈
            remove = ()=>{
                this.arr.pop()
            }
            // 获取栈的长度
            getLength = ()=>{
                return this.arr.length;
            }
        }
        var removeOuterParentheses = function(S) {
            // 初始化Stack
            let arr = [];
            let newStack = new Stack();
            let str = '';
            // 用来记录最外层括号的位置
            let start = 0;
            let end = 0;
            for(let i =0,len=S.length;i<len;i++){
                let newChar = S.charAt(i);
                // 如果栈里边没有值 则记录最外层括号的起始位置
                if(newStack.getLength() == 0){
                    start = i;
                }
                if(newChar == '('){
                    newStack.add('(')
                }else if(newChar == ')'){
                    // 移除配对的括号
                    newStack.remove()
                    if(newStack.getLength() ==0){
                        // 如果栈被清空 则记录最外层括号的终点位置
                        end = i;
                        arr.push({
                            start:start,
                            end:end
                        })
                    }
                }
            }
            console.log(arr)
            // 去掉最外层括号 得到原语 组合起来
            for(let i =0,len = arr.length;i<len;i++){
                let newStr = S.substring(arr[i].start+1,arr[i].end);
                // console.log(newStr)
                str+=newStr
            }
            return str;
        };
        // console.log(removeOuterParentheses("(()())(())"))
```

