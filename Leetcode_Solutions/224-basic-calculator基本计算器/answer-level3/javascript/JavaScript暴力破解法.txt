 执行用时 :116 ms, 在所有 JavaScript 提交中击败了84.75%的用户
 内存消耗 :37.9 MB, 在所有 JavaScript 提交中击败了76.47%的用户

```
var calculate = function(s) {
    let arr = [], temp = '';

    for (let i = 0; i < s.length; i++){
        temp = s[i];

        if (temp == ' ') continue;
        else if(temp >= '0' && temp <= '9'){ //数字，碰到数字往前计算
            while(s[i+1] >= '0' && s[i+1] <= '9' && i<s.length-1){
                temp += s[i+1];
                i++;
            }
            arr.push(temp);
            getResult(arr);
        }
        else{ //其他左右括号，和+-号
            arr.push(temp);

            if (temp == ')'){ //碰到右括号往前计算
                getResult(arr);
            }
        }
    }
    return arr.length == 1 ? arr[0] : 0;
}

//从栈顶往栈底计算
function getResult(arr){
    while(true){
        if (arr.length < 2) break;

        let last = arr.pop();

        if (last == ')'){
            let last_p = parseInt(arr.pop()), last_p_p = arr.pop();

            if (last_p_p == "("){
                arr.push(last_p);
            }
            else{ //+ 或 -
                let num = parseInt(arr.pop());
                arr.push(last_p_p == "+" ? num + last_p : num - last_p);
                arr.push(")")
            }
        }
        else{ //last为数字
            let last_p = arr.pop();

            if (last_p == "("){ //停止循环
                arr.push("(");
                arr.push(last);
                break;
            }
            else{ //last_p 为 + 或 -
                last = parseInt(last);
                let num = parseInt(arr.pop())
                arr.push(last_p == "+" ? num + last : num - last);
            }
        }
    }
}
```
