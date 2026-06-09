### 解题思路
首先词法分析，得到num variable 和 关键字
语法分析 构建语法树
在语法树上 附加Context 上限文数据
线性执行语法树即可


### 代码

```csharp

enum LispToken{
    Let,
    Num,
    Add,
    Mult,
    Left,
    Right,
    Variable,
}
class LToken
{
    public LispToken tp;
    public int numV = 0;
    public string varName = null;
    public bool neg = false;
    public StringBuilder sb;
    public void GetVarName(){
        if(sb == null) return;
        var n = sb.ToString();
        varName = n;
        if(n == "let"){
            tp = LispToken.Let;
        }else if(n == "add"){
            tp = LispToken.Add;
        }else if(n == "mult"){
            tp = LispToken.Mult;
        }else {
        }
        sb = null;
    }
}
//(add exp exp)
//(mul exp exp)
//num
//variable
//(let v1 e1 v2 e2 exp)

class AddSyntax : LSyntax{
    enum State {
        Start,
        B,
        Finish,
    }
    State state = State.Start;
    public override int Parse(int pos, out LSyntax node){
        if(state == State.Start){
            state = State.B;
            return ParseExp(pos, out node);
        }
        if(state == State.B){
            state = State.Finish;
            return ParseExp(pos, out node);
        }
        node = parent;
        return pos;
    }
    public override int Eval(){
        var v1 = children[0].Eval();
        var v2 = children[1].Eval();
        return v1 + v2;
    }
}
class LetSyntax:LSyntax{
    enum State {
        Start,
        Exp,
        Var,
        Finish,
    }
    State state = State.Start;
    public override int Parse(int pos, out LSyntax node){
        var tk = LispParse.toks[pos];
        if(state == State.Start){//Var exp var exp exp
            if (tk.tp == LispToken.Variable)
            {
                var at = new AtomicSync();
                at.token = tk;
                at.parent = this;
                children.Add(at);
                node = this;
                state = State.Exp;
                return pos + 1;
            }else {//Number 或者 Exp
                state = State.Finish; //结束读取 直接计算Exp
                return ParseExp(pos, out node);
            }
        }else if(state == State.Exp) {//Var Exp
            if(tk.tp == LispToken.Right) {//Var 就是表达式 结束了Group 语法
                node = parent;
                return pos;
            }
            //Number Variable Exp
            state = State.Var;
            return ParseExp(pos, out node);
        }else if(state == State.Var){
            if (tk.tp == LispToken.Variable)
            {
                var at = new AtomicSync();
                at.token = tk;
                at.parent = this;
                children.Add(at);
                node = this;
                state = State.Exp;
                return pos + 1;
            }else {//Number 或者 Exp
                state = State.Finish; //结束读取 直接计算Exp
                return ParseExp(pos, out node);
            }
        }else if(state == State.Finish){
            node = parent;
            return pos;
        }
        node = Error;
        return pos + 1;
    }
    public override int Eval(){
        var cn = children.Count;
        var vNum = cn / 2;
        //Console.WriteLine("Let:" + cn + ":" + vNum);
        for (var i = 0; i < vNum; i++){
            var vi = i * 2;
            var ei = i * 2 + 1;
            var v = children[vi] as AtomicSync;
            var e = children[ei];
            var ev = e.Eval();
            context[v.token.varName] = ev;
            //Console.WriteLine("SetV:" + v.token.varName + ":" + ev);
        }
        return children[cn - 1].Eval();
    }
}

class MulSyntax : LSyntax{
    enum State {
        Start,
        B,
        Finish,
    }
    State state = State.Start;
    public override int Parse(int pos, out LSyntax node){
        if(state == State.Start){
            state = State.B;
            return ParseExp(pos, out node);
        }
        if(state == State.B){
            state = State.Finish;
            return ParseExp(pos, out node);
        }
        node = parent;
        return pos;
    }
    public override int Eval(){
        var v1 = children[0].Eval();
        var v2 = children[1].Eval();
        return v1 * v2;
    }
}
class GroupSyntax : LSyntax{
    enum State {
        Start,
        Mid,
    }
    State state = State.Start;
    public override int Parse(int pos, out LSyntax node){
        var tk = LispParse.toks[pos];
        if (state == State.Start)
        {
            state = State.Mid;
            if (tk.tp == LispToken.Let)
            {
                var let = new LetSyntax();
                let.parent = this;
                children.Add(let);
                node = let;
                return pos + 1;
            }
            else if (tk.tp == LispToken.Add)
            {
                var ad = new AddSyntax();
                ad.parent = this;
                children.Add(ad);
                node = ad;
                return pos + 1;
            }
            else if (tk.tp == LispToken.Mult)
            {
                var mul = new MulSyntax();
                mul.parent = this;
                children.Add(mul);
                node = mul;
                return pos + 1;
            }
        }
        //")"
        node = parent;
        return pos + 1;
    }
    public override int  Eval(){
        var ev = children[0].Eval();
        //Console.WriteLine("CEv:" + children[0] + ":" + ev);
        return ev;
    }
}
//变量或者Num
class AtomicSync : LSyntax {
    public LToken token;
    public override int Eval(){
        if(token.tp == LispToken.Num){
            if(token.neg) return -1 * token.numV;
            return token.numV;
        }
        // ////Console.WriteLine("Atomatic:" + ObjectDumper.Dump(token));
        if(token.varName == null) token.GetVarName();
        //Variable
        var p = parent;
        var vn = token.varName;
        while(p!= null){
            if(p.context.ContainsKey(vn)) return p.context[vn];
            p = p.parent;
        }
        return Int32.MinValue;
    }
}

class LSyntax{
    public Dictionary<string, int> context = new Dictionary<string, int>();
    public LSyntax parent;
    public List<LSyntax> children = new List<LSyntax>();
    public virtual int Parse(int pos, out LSyntax node){
        return ParseExp(pos, out node);
    }
    public static LSyntax Error = new LSyntax();
    public int ParseExp(int pos, out LSyntax node){
        var tk = LispParse.toks[pos];
        if(tk.tp == LispToken.Left){
            var ng = new GroupSyntax();
            ng.parent = this;
            children.Add(ng);
            node = ng;
            return pos + 1;
        }
        //Number 不能继续深入
        if(tk.tp == LispToken.Num){
            var a = new AtomicSync();
            children.Add(a);
            a.parent = this;
            a.token = tk;
            // node = a;
            node = this;
            return pos + 1;
        }
        if(tk.tp == LispToken.Variable){
            var a = new AtomicSync();
            children.Add(a);
            a.parent = this;
            a.token = tk;
            // node = a;
            //varialbe 不能深入
            node = this;
            return pos + 1;
        }

        node = Error;
        return pos + 1;
    }
    public virtual int Eval(){
        return children[0].Eval();
    }
}
class LispParse{
    public static List<LToken> toks;
    public int Evaluate(string expression)
    {
        var root = new LSyntax();
        var curNode = root;
        toks = new List<LToken>();
        LToken curToken = null;
        for (var i = 0; i < expression.Length; i++)
        {
            var c = expression[i];
            if (c == ' ')
            {
                if (curToken != null && curToken.tp == LispToken.Variable)
                {
                    curToken.GetVarName();
                }
                curToken = null;
            }
            else if (c == '(')
            {
                if(curToken != null) curToken.GetVarName();
                curToken = new LToken()
                {
                    tp = LispToken.Left,
                };
                toks.Add(curToken);
                curToken = null;
            }
            else if (c == ')')
            {
                if(curToken != null) curToken.GetVarName();
                curToken = new LToken()
                {
                    tp = LispToken.Right,
                };
                toks.Add(curToken);
                curToken = null;
            }
            else if (c == '-')
            {
                if(curToken != null) curToken.GetVarName();
                curToken = new LToken()
                {
                    tp = LispToken.Num,
                    neg = true,
                    numV = 0,
                };
                toks.Add(curToken);
            }
            else if (c >= '0' && c <= '9')
            {
                if (curToken != null && curToken.tp == LispToken.Variable)
                {
                    curToken.sb.Append(c);
                }else
                {
                    if (curToken == null || curToken.tp != LispToken.Num)
                    {
                        curToken = new LToken()
                        {
                            tp = LispToken.Num,
                            neg = false,
                            numV = 0,
                        };
                        toks.Add(curToken);
                    }
                    curToken.numV *= 10;
                    curToken.numV += c - '0';
                }
            }else if(c >= 'a' && c <= 'z'){
                if(curToken == null || curToken.tp != LispToken.Variable){
                    curToken = new LToken()
                    {
                        tp = LispToken.Variable,
                        sb = new StringBuilder(),
                    };
                    toks.Add(curToken);
                }
                curToken.sb.Append(c);
            }
        }
        //Console.WriteLine("Tokens:"+ObjectDumper.Dump(toks));
        for (var i = 0; i < toks.Count;)
        {
            //Console.WriteLine("CurNode:"+i+":"+ObjectDumper.Dump(toks[i]));
            i = curNode.Parse(i, out var newNode);
            //Console.WriteLine(":"+curNode+":"+newNode+":##:\n");
            curNode = newNode;
        }
        //Console.WriteLine("ParseOK");
        return curNode.Eval();
    }
    // static void Main(string[] arg)
    // {
    //     var lp = new LispParse();
    //     // var r = lp.Evaluate("(add 1 2)");
    //     // var r = lp.Evaluate("(mult 3 (add 2 3))");
    //     // var r = lp.Evaluate("(let x 2 (mult x 5))");
    //     // var r = lp.Evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))");
    //     // var r = lp.Evaluate("(let x 3 x 2 x)");
    //     // var r = lp.Evaluate("(let x 1 y 2 x (add x y) (add x y))");
    //     // var r = lp.Evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))");
    //     // var r = lp.Evaluate("(let a1 3 b2 (add a1 1) b2) ");
    //     var r = lp.Evaluate("(let a (add 1 2) b (mult a 3) c 4 d (add a b) (mult d d))");
    //     //Console.WriteLine(r);
    // }
}
public class Solution {
    public int Evaluate(string expression) {
        var lp = new LispParse();
        return lp.Evaluate(expression);
    }
}
```