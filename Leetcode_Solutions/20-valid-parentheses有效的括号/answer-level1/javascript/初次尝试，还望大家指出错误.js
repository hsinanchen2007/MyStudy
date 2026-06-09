### 解题思路
此处撰写解题思路
顺序遍历，[, (, {入栈，当遍历出现}, ), ]，则将原有的栈顶元素推出，与当前遍历的符号进行比对，
最终栈里没有元素这符合要求。
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 * 此题解题思路：
 * 遍历[, (, {等符号进栈
 * 遍历}, ), ]等符号出栈，与之配对，最终栈里没有元素则符合要求，注意边界问题
 */
var isValid = function(s) {
    if(s == ''||s == undefined){
        return true;
    }
    var Stack = function(){
        let items = [];
        this.push = function(item){
            items.push(item);
        }
        this.pop = function(){
            return items.pop();
        }
        this.size = function(){
            return items.length;
        }
        this.isEmpty = function(){
            return items.length == 0;
        }
        this.peek = function(){
            return items[items.length-1];
        }
        return items;
    }
    let stack = new Stack();
    let arr = s.split('');
    let keys = {
        '}': '{',
        ']': '[',
        ')': '(',
    }
    let flag = true;
    for(i=0; i< arr.length; i++){
        if(['(', '{', '['].indexOf(arr[i]) !== -1){
            stack.push(arr[i]);
        } else if([')', '}', ']'].indexOf(arr[i]) !== -1){
            let a = stack.pop();
            if(!a){ // 栈不存在数据，退出
                flag = false;
                break;
            }else{
                if(keys[arr[i]] != a){
                    flag = false;
                    break;
                }
            }
        }
    } 
    if(stack.length>0){
        flag = false;
    }
    return flag;
};
```