&emsp;&emsp;我采用了一个数组去模拟递归的过程，为了可以处理纯数字，我在读入的字符串后面加入了“#”当成终结符，我们把输入分成几种情况讨论就行了：
1. “#”和“,”：不做任何处理；
2. “[”: 压栈一个“$”作为标记；
3. “]”：退栈直到遇到一个“$”,生成列表节点；
4. 数字: 先暂存在chars中，当遇到一个非数字字符且chars不为空时，生成一个整数节点；

代码如下：
```javascript
var deserialize = function(s) {
    let ws = [], chars = [], cache = [];
    s = s + "#";
    for(let i=0; i < s.length; ++i) {
        if(chars.length && isNaN(s[i])) {
            let num_node = new NestedInteger(); 
            num_node.setInteger(chars.join("") | 0);
            ws.push(num_node);
            chars.length = 0;
        }
        switch(s[i]) {
            case "#":
            case ",": break;
            case "[": ws.push("$"); break;
            case "]":
                let e, list_node = new NestedInteger();
                while((e = ws.pop()) != "$") cache.push(e);
                while(cache.length) list_node.add(cache.pop()); 
                ws.push(list_node);
                break;
            default:
                chars.push(s[i]);
                break;
        }
    }
    return ws[0];
};
```