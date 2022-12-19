### 解题思路
解析中构造AST
驱动力由 遍历Token驱动
返回当前AST 解析位置 和 Token读取位置
LL(1) 文法

### 代码

```csharp
enum BTTEnum{
    TRUE,
    FALSE,
    NOT,
    AND,
    OR,
    COMMA,
    LEFT,
    RIGHT,
}
class BToken{
    public BTTEnum type;
}
enum ASTType{
    ROOT,
    EXP,
    TOKEN,
    ERROR,
}
class NotBAST : BAST{
    enum STATE{
        LEFT,
        MID,
        RIGHT,
    }
    private STATE state;
    public NotBAST(){
        state = STATE.LEFT;
    }
    public override (int, BAST) ReadToken(List<BToken> all, int index){
        var tk = all[index];
        if(state == STATE.LEFT){
            if(tk.type != BTTEnum.LEFT) return (index+1, error);
            state = STATE.MID;
            return (index + 1, this);
        }
        if(state == STATE.MID){
            state = STATE.RIGHT;
            return ParseExp(all, index);
        }
        if(state == STATE.RIGHT){
            if(tk.type != BTTEnum.RIGHT) return (index + 1, error);
            return (index + 1, parent);
        }
        return (index + 1, error);
    }
    public override bool Eval(){
        return !children[0].Eval();
    }
}

class BinBAST : BAST{
    enum STATE{
        LEFT,
        MID,
    }
    private STATE state;
    public BinBAST(){
        state = STATE.LEFT;
    }
    private bool firstExp = true;
    //Left exp, exp, exp, Right
    public override (int, BAST) ReadToken(List<BToken> all, int index)
    {
        var tk = all[index];
        if(state == STATE.LEFT){
            if(tk.type != BTTEnum.LEFT) return (index+1, error);
            state = STATE.MID;
            return (index + 1, this);
        } 
        if(state == STATE.MID){
            if (firstExp)
            {
                firstExp = false;
                return ParseExp(all, index);//读取一个表达式
            }else {
                if(tk.type == BTTEnum.COMMA){//后面更多的表达式
                    return ParseExp(all, index + 1);
                }
                if(tk.type == BTTEnum.RIGHT){//没有表达式了
                    return (index + 1, parent);
                }
                return (index + 1, error);
            }
        }
        return (index + 1, error);
    }
    public override bool Eval(){
        if(token.type == BTTEnum.AND){
            foreach(var c in children){
                var e = c.Eval();
                if(!e) return false;
            }
            return true;
        }else {
            foreach(var c in children) {
                if(c.Eval()) return true;
            }
            return false;
        }
    }
}
class ErrBAST : BAST{
    public override (int, BAST) ReadToken(List<BToken> all, int index)
    {
        return (index + 1, this);
    }
}
class BAST{
    public ASTType type = ASTType.ROOT;
    public List<BAST> children = new List<BAST>();
    public BAST parent = null;
    public BToken token;
    public static BAST error = new ErrBAST()
    {
        type = ASTType.ERROR,
    };

    public virtual bool Eval(){
        if (type == ASTType.ROOT)
        {
            return children[0].Eval();
        }
        if(type == ASTType.ERROR) return false;
        if(type == ASTType.TOKEN) {
            return token.type == BTTEnum.TRUE;
        }
        //EXP 自己估算
        return false;
    }
    public (int, BAST) ParseExp(List<BToken> all, int index)
    {
        var tk = all[index];
        if (tk.type == BTTEnum.TRUE || tk.type == BTTEnum.FALSE)
        {
            var c = new BAST()
            {
                type = ASTType.TOKEN,
                token = tk,
            };
            c.parent = this;
            children.Add(c);
            return (index + 1, this);
        }
        if (tk.type == BTTEnum.NOT)
        {
            var c = new NotBAST()
            {
                type = ASTType.EXP,
                token = tk,
            };
            c.parent = this;
            children.Add(c);
            return (index + 1, c);
        }
        if (tk.type == BTTEnum.AND || tk.type == BTTEnum.OR)
        {
            var c = new BinBAST()
            {
                type = ASTType.EXP,
                token = tk,
            };
            c.parent = this;
            children.Add(c);
            return (index + 1, c);
        }
        if(tk.type == BTTEnum.COMMA){
            return (index, parent);
        }
        if(tk.type == BTTEnum.RIGHT){
            return (index, parent);
        }
        return (index + 1, error);
    }
    public virtual (int, BAST) ReadToken(List<BToken> all, int index){
        return ParseExp(all, index);
    }
}
class WhatBool{

    public bool ParseBoolExpr(string expression) {
        var allToken = new List<BToken>();
        foreach(var c in expression){
            if(c == ' '){
            }else if(c == 't'){
                var tk = new BToken()
                {
                    type = BTTEnum.TRUE,
                };
                allToken.Add(tk);
            }else if(c == 'f'){
                var tk = new BToken()
                {
                    type = BTTEnum.FALSE,
                };
                allToken.Add(tk);
            }else if(c == '!'){
                var tk = new BToken()
                {
                    type = BTTEnum.NOT,
                };
                allToken.Add(tk);
            }else if(c == '&'){
                var tk = new BToken()
                {
                    type = BTTEnum.AND,
                };
                allToken.Add(tk);
            }else if(c == '|') {
                var tk = new BToken() { type = BTTEnum.OR, };
                allToken.Add(tk);
            }else if(c == '(') {
                var tk = new BToken() { type = BTTEnum.LEFT, };
                allToken.Add(tk);
            }else if(c == ')'){
                var tk = new BToken() { type = BTTEnum.RIGHT, };
                allToken.Add(tk);
            }else if(c == ','){
                var tk = new BToken() { type = BTTEnum.COMMA, };
                allToken.Add(tk);
            }
        }
        var ast = new BAST()
        {
            type = ASTType.ROOT,
        };
        //结合当前Node 上下文 和 当前Token位置
        var curAst = ast;
        for (var i = 0; i < allToken.Count;){
            var ret = curAst.ReadToken(allToken, i);
            curAst = ret.Item2;
            i = ret.Item1;
        }

        return ast.Eval();
    }
}

public class Solution {
    public bool ParseBoolExpr(string expression) {
        var wb = new WhatBool();
        return wb.ParseBoolExpr(expression);
    }
}
```