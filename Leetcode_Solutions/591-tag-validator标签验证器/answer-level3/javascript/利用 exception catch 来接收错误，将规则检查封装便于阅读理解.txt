本质上这应该是一个词法分析器，我现在把应该写成状态机的部分简化了，手动的维护了几个状态
是否进入cdata，当前tag栈，当前未解析完成的tag name，当前的tag解析状态
然后状态转移进行代码分析。

基本思路是把规则检查的部分从代码分析的过程中抽离出来，使代码分析的过程更加清晰，同时通过捕获异常的方式来接收代码分析过程中违反规则的错误，以简化规则检查的复杂程度。

```

var isValid = function(code) {
    // 设置多个检查函数 检查失败就抛出异常 在运行时catch异常
    function checkBeginning(code){ // rule 1
        if(!(code[0] === '<' && code[1] !== '/' && code[1] !== '!')){
            throw 'beginning error';
        }
    }
    function checkEndding(code){ //rule 1
        if(code[code.length - 1] !== '>'){
            throw 'endding error';
        }
    }
    function checkTagName(name){ // rule 3
        if(name.length < 1 || name.length > 9){
            throw 'tag name length error';
        }
        for(let i = 0; i < name.length; ++i){
            if(name[i].charCodeAt() < ('A').charCodeAt() || name[i].charCodeAt() > ('Z').charCodeAt()){
                throw 'tag name char error';
            }
        }
    }
    function checkTagClosed(tagStack, tag){// rule 2
        if(tagStack[tagStack.length - 1] !== tag){
            throw 'tag match error';
        }
    }
    function checkOneTagRoot(tagStack, code, i){// rule 1
        if(tagStack.length === 0 && code.length - i > 1){
            throw 'tag one root error';
        }
    }

    try{
        checkBeginning(code);
        checkEndding(code);

        // 需要记录几个状态， 是否进入cdata，当前tag栈，当前未解析完成的tag name，当前的tag解析状态
        let cdataState = false;
        let tagStack = [];
        let tagName = '';
        let tagState = null; // null begin end

        let i = 0;
        while(i < code.length){
            let current = code[i];
            if(cdataState){ // 处于 cdataState
                if(current ===']' && code.substr(i, 3) === ']]>'){
                    cdataState = false;
                    i += 3;
                }else{
                    ++i;
                }
            }else{
                if(tagState){
                    if(current === '>'){
                        checkTagName(tagName);
                        if(tagState === 'begin'){
                            tagStack.push(tagName);
                        }else{
                            checkTagClosed(tagStack, tagName);
                            tagStack.pop();
                            checkOneTagRoot(tagStack, code, i);
                        }
                        tagState = null;
                        ++i;
                    }else{
                        tagName += current;
                        ++i;
                    }
                }else{
                    if(current === '<'){
                        if(code[i + 1] === '/'){
                            tagState = 'end';
                            tagName = '';
                            i += 2;
                        }else if(code.substr(i, 9) === '<![CDATA['){
                            cdataState = true;
                            i += 9;
                        }else{
                            tagState = 'begin';
                            tagName = '';
                            i += 1;
                        }
                    }else{
                        ++i;
                    }
                }
            }
        }
        if(cdataState === false && tagState === null && tagStack.length === 0){
            return true;
        }
        return false;
    }catch(e){
        // console.log(e)
        return false;
    }
};
```
