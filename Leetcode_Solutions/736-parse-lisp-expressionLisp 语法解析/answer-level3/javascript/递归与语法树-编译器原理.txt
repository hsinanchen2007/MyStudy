1. **递归法**
第一种比较容易想到的解法应该就是这种递归法了(另外，这种方法也比较快速)，递归法解决add和mult嵌套的问题并不难，关键是let比较难以处理，我这里采用的是作用域拷贝，即内层的作用域拷贝外层的作用域，再修改得到新的作用域的方法。程序的代码如下：

```javascript
var evaluate = function(expression) {

    // 当前执行的位置 k, 作用域 field
    let runtime = (k, field = {}) => {
        let syntax = "",
            vals = [],
            op = null,
            process = [];
        while(k < expression.length) {
            switch(expression[k]) {
                case ' ':
                    // 当收集的串不为空串时
                    if (syntax) {
                        // 若操作为null时
                        if(!op) {
                            // 先对操作赋值
                            op = syntax;
                            // 如果操作为let 则复制作用域
                            if(op == "let") {
                                field = {
                                    ...field
                                };
                            }
                        } else if(op == "let") {
                            process.push(syntax);
                            // 若待处理的结果里有两个值
                            if(process.length >= 2) {
                                let v = parseFloat(process[1]);
                                if (isNaN(v)) {
                                    // 如果值为非数，则从作用域中取得
                                    field[process[0]] = field[process[1]];
                                } else {
                                    // 如果值为数字，则直接赋值
                                    field[process[0]] = v;
                                }
                                // 清空待处理数组
                                process.length = 0;
                            }
                        } else {
                            // 其他情况下，默认为参数
                            vals.push(syntax);
                        }
                        syntax = "";
                    }
                    ++k;
                    break;
                case '(':
                    // 当遇到左括号时，递归处理子式
                    let returns = runtime(k + 1, field);
                    // 如果操作为let
                    if(op == "let") {
                        // 对作用域赋值进行处理
                        process.push(returns[0]);
                        if(process.length >= 2) {
                            field[process[0]] = parseFloat(process[1]);
                            process.length = 0;
                        }
                    }
                    // 保存子式的结果
                    vals.push(returns[0]);
                    // 刷新当前处理的字符串的右边界
                    k = returns[1];
                    break;
                case ')':
                    // 当遇到右括号时计算子式的值
                    if(syntax) vals.push(syntax);
                    // 转换参数列表里面的值
                    vals = vals.map(val => isNaN(parseFloat(val))? field[val]: val);
                    // 对不同的操作执行不同的方法
                    switch(op) {
                        case "add":
                            // 相加
                            let add = parseFloat(vals[0]) + parseFloat(vals[1]);
                            return [add, k + 1];
                        case "mult":
                            // 相乘
                            let mult = parseFloat(vals[0]) * parseFloat(vals[1]);
                            return [mult, k + 1];
                        case "let":
                            // 当操作为let时直接返回最后一个参数的值
                            return [vals[vals.length - 1], k + 1];
                    }
                    break;
                default:
                    // 其余情况下，收集字符形成字符串
                    syntax += expression[k++];
            }
        }
        return vals[0];
    };

    return runtime(0);
};
```

2. **语法树** 另外一种比较中规中矩的方法就是先构造一棵语法树，然后先序遍历语法树进行求解，这种方法的速度是没有上面那个方法快的，但是效果非常好看，大家如果感兴趣的话，可以自己运行一下，将代码中的 root.display() 解注释，然后运行，就可以看到解析好的语法树。首先，要构造这样一个解析器，自然少不了《编译器原理》里的内容了，对应编译原理里的语法分析，构造语法分析树。然后，我们先把递推式列一下：
* Exp -> (Dec|Add|Mult)
* Add -> add Exp|name|number Exp|name|number
* Mult -> mult Exp|name|number Exp|name|number
* Dec -> let C Exp
* C -> name Exp|name|number C | none
* name -> valid name of variable
* number -> valid number

&emsp;&emsp;以上就是全部的递推式了，如果对递推式有疑问的话，可以自行翻看《编译器原理》。接下来，我们只要实现这个递推式，就可以构建语法树了。

```javascript
var evaluate = function(expression) {
    // 语法树节点
    function SyntaxNode(type) {
        const STDNAME = /^[a-zA-Z\$_][a-zA-Z\d_]*$/;
        this.type = type;
        this.catholic = [];
        this.names = [];
        this.addNext = (x) => {
            if (x instanceof SyntaxNode) {
                this.catholic.push(x);
            } else if(STDNAME.test(x)) {
                let name_node = new SyntaxNode(Symbol.for("name"));
                name_node.catholic.push(x);
                this.catholic.push(name_node);
            } else {
                let num_node = new SyntaxNode(Symbol.for("number"));
                num_node.catholic.push(x);
                this.catholic.push(num_node);
            }
            if (type == Symbol.for("Dec")) {
                if(this.catholic.length >= 2) {
                    let value = this.catholic.pop(),
                        key = this.catholic.pop();
                    if(key.type == Symbol.for("name")) {
                        let c = new SyntaxNode(Symbol.for("C"));
                        c.addNext(key);
                        c.addNext(value);
                        this.catholic.push(c);
                    } else {
                        this.catholic.push(key);
                        this.catholic.push(value);
                    }
                }
            }
        };
        this.process = (field = {}) => {
            let vals = this.catholic;
            switch(type) {
                case Symbol.for("Add"):
                    return vals[0].process(field) + vals[1].process(field);
                case Symbol.for("Mult"):
                    return vals[0].process(field) * vals[1].process(field);
                case Symbol.for("Exp"):
                    return vals[0].process(field);
                case Symbol.for("Dec"):
                    for(let e of vals) {
                        if(e.type == Symbol.for("C")) {
                            let p = e.process(field);
                            field = { ...field, ...{[p.k]: p.v} };
                        }
                    }
                    return vals[vals.length - 1].process({ ...field });
                case Symbol.for("C"):
                    return {k: vals[0].catholic[0], v: vals[1].process(field)};
                case Symbol.for("name"):
                    return field[vals[0]];
                case Symbol.for("number"):
                    return parseFloat(vals[0]);
            }
        };
        this.display = (blanks = 0) => {
            console.log(" ".repeat(blanks) + type.toString());
            for(let e of this.catholic) {
                if (e instanceof SyntaxNode) {
                    e.display(blanks + 2);
                } else {
                    console.log(" ".repeat(blanks) + e);
                }
            }
        }
    }

    // 构造语法树
    function generateSyntaxTree(exp, k) {
        let syntax = "", node = null;
        while(k < exp.length) {
            switch(exp[k]) {
                case '(':
                    let returns = generateSyntaxTree(exp, k + 1);
                    if (node) {
                        let cache = new SyntaxNode(Symbol.for("Exp"));
                        cache.addNext(returns[0]);
                        node.addNext(cache);
                        k = returns[1] + 1;
                    } else {
                        node = new SyntaxNode(Symbol.for("Exp"));
                        node.addNext(returns[0]);
                        k = returns[1];
                    }
                    break;
                case ' ':
                    if(!syntax) {
                        ++k;
                        break;
                    }
                    switch(syntax) {
                        case "add":
                            node = new SyntaxNode(Symbol.for("Add"));
                            break;
                        case "mult":
                            node = new SyntaxNode(Symbol.for("Mult"));
                            break;
                        case "let":
                            node = new SyntaxNode(Symbol.for("Dec"));
                            break;
                        default:
                            node.addNext(syntax);
                            break;
                    }
                    syntax = "", ++k;
                    break;
                case ')':
                    if(syntax && node) node.addNext(syntax);
                    return [node, k];
                default:
                    syntax += exp[k++];
                    break;
            }
        }
        if (!node) throw new Error("parsing fail.");
        return [node, k];
    }

    let root = generateSyntaxTree(expression, 0)[0];
    // root.display();
    return root.process();
};
```

&emsp;&emsp;如果对于这样一个输入的串"(let x 2 (mult x (let x 3 y 4 (add x y))))"，构造完语法树之后就会变成如下的表示：
```
Symbol(Exp)
  Symbol(Dec)
    Symbol(C)
      Symbol(name)
      x
      Symbol(number)
      2
    Symbol(Exp)
      Symbol(Mult)
        Symbol(name)
        x
        Symbol(Exp)
          Symbol(Dec)
            Symbol(C)
              Symbol(name)
              x
              Symbol(number)
              3
            Symbol(C)
              Symbol(name)
              y
              Symbol(number)
              4
            Symbol(Exp)
              Symbol(Add)
                Symbol(name)
                x
                Symbol(name)
                y
```
&emsp;&emsp;当然，如果要照搬《编译器原理》的内容，应该先从词法分析开始，然后才能进行语法分析。这样虽然忽略了词法分析，但也可以通过这道题，练习和理解我们程序编译运行的基本原理。最后，再写一个加强版的Lisp语法解析器，加入了减法和除法，以及多个数的加法。

```javascript
var evaluate = function(expression) {
    const EXP = "Exp";
    const ADD = "Add";
    const SUB = "Sub";
    const COB = "C";
    const DIV = "Div";
    const MULT = "Mult";
    const NUM = "number";
    const VAR = "var";
    const DEC = "Dec";
    const ADD3 = "Add_3"

    // 语法树节点
    function SyntaxNode(type) {
        const STDNAME = /^[a-zA-Z\$_][a-zA-Z\d_]*$/;
        this.type = type;
        this.children = [];
        this.names = [];
        this.addNext = (x) => {
            if (x instanceof SyntaxNode) {
                this.children.push(x);
            } else if(STDNAME.test(x)) {
                let name_node = new SyntaxNode(VAR);
                name_node.children.push(x);
                this.children.push(name_node);
            } else {
                let num_node = new SyntaxNode(NUM);
                num_node.children.push(x);
                this.children.push(num_node);
            }
            if (type == DEC) {
                if(this.children.length >= 2) {
                    let value = this.children.pop(),
                        key = this.children.pop();
                    if(key.type == VAR) {
                        let c = new SyntaxNode(COB);
                        c.addNext(key);
                        c.addNext(value);
                        this.children.push(c);
                    } else {
                        this.children.push(key);
                        this.children.push(value);
                    }
                }
            }
        };
        this.process = (field = {}) => {
            let vals = this.children;
            switch(type) {
                case SUB:
                    return vals[0].process(field) - vals[1].process(field);
                case DIV:
                    return vals[0].process(field) / vals[1].process(field);
                case ADD:
                    return vals[0].process(field) + vals[1].process(field);
                case ADD3:
                    return vals.map(val => val.process(field)).reduce((a,b) => a + b, 0);
                case MULT:
                    return vals[0].process(field) * vals[1].process(field);
                case EXP:
                    return vals[0].process(field);
                case DEC:
                    for(let e of vals) {
                        if(e.type == COB) {
                            let p = e.process(field);
                            field = { ...field, ...{[p.k]: p.v} };
                        }
                    }
                    return vals[vals.length - 1].process({ ...field });
                case COB:
                    return {k: vals[0].children[0], v: vals[1].process(field)};
                case VAR:
                    return field[vals[0]];
                case NUM:
                    return parseFloat(vals[0]);
            }
        };
        this.display = (blanks = 0) => {
            let str = " ".repeat(blanks) + type.toString() + "\n";
            for(let e of this.children) {
                if (e instanceof SyntaxNode) {
                    str += e.display(blanks + 2);
                } else {
                    str += " ".repeat(blanks) + e + "\n";
                }
            }
            return str;
        }
    }

    // 构造语法树
    function generateSyntaxTree(exp, k) {
        let syntax = "", node = null;
        while(k < exp.length) {
            switch(exp[k]) {
                case '(':
                    let returns = generateSyntaxTree(exp, k + 1);
                    if (node) {
                        let cache = new SyntaxNode(EXP);
                        cache.addNext(returns[0]);
                        node.addNext(cache);
                        k = returns[1] + 1;
                    } else {
                        node = new SyntaxNode(EXP);
                        node.addNext(returns[0]);
                        k = returns[1];
                    }
                    break;
                case ' ':
                    if(syntax) {
                        switch(syntax) {
                            case "sub":
                                node = new SyntaxNode(SUB);
                                break;
                            case "add3":
                                node = new SyntaxNode(ADD3);
                                break;
                            case "add":
                                node = new SyntaxNode(ADD);
                                break;
                            case "mult":
                                node = new SyntaxNode(MULT);
                                break;
                            case "div":
                                node = new SyntaxNode(DIV);
                                break;
                            case "let":
                                node = new SyntaxNode(DEC);
                                break;
                            default:
                                node.addNext(syntax);
                                break;
                        }
                    }
                    syntax = "", ++k;
                    break;
                case ')':
                    if(syntax && node) node.addNext(syntax);
                    return [node, k];
                case '\r':
                case '\b':
                case '\n':
                    ++k;
                    break;
                default:
                    syntax += exp[k++];
                    break;
            }
        }
        if (!node) throw new Error("parsing fail.");
        return [node, k];
    }

    return generateSyntaxTree(expression, 0)[0];
};
```

&emsp;&emsp;最后，我们用这个解析器运行一下这个超复杂的式子：
```javascript
let root = evaluate(`(let t 1 y (add t t) l (sub (add3 t t t t t) y)
    u (mult (mult y y) y) h (mult u (add3 t y y)) (sub (let p (sub (
        let m (mult y l) (sub (mult m (add (let q t q) y)) (add (mult m t) (div m l)))
    ) y) x (mult p (let t (sub l y) (sub (let i l (mult i y)) t)))
        (mult x (add3 p (let t l (sub p t)) (div p u)))) h))`);
// console.log(root.display());
console.log(root.process());
```
&emsp;&emsp;最终的结果是520