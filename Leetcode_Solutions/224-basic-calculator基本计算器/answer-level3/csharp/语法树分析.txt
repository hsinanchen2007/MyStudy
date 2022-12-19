### 解题思路
Exp = Two
Exp = Num
Exp = Group
Group = Left Exp Right
Two = Exp Op Exp
Num = digits

LL(1) 文法

### 代码

```csharp
using VT = System.ValueTuple<int, Calc.Syntax>;
class Calc{
    enum Token {
        L,
        R,
        P,
        M,
        Num,
        
    }
    class TokenV{
        public Token type;
        public int c;
    }
    //Single Or Two
    class NumSync : Syntax{
        private int value;
        public override int Eval(){
            return value;
        }
        public override VT Parse(int i)
        {
            var v = 0;
            var finishPos = i;
            for (var j = i; j < tlst.Count; j++, finishPos++){
                var tk = tlst[j];
                if(tk.type == Token.Num) {
                    v *= 10;
                    v += tk.c;
                }else {
                    break;
                }
            }
            value = v;
            if(finishPos >= tlst.Count) return (finishPos, parent);
            return (finishPos, parent);
        }
    }
    //Exp 本身无括号
    //((Exp)+(Exp))
    class ExpSync : Syntax {
        enum State
        {
            Begin, Mid, End,
        }
        State state = State.Begin;
        public override int Eval(){
            var c0 = children[0];
            //num or two
            return c0.Eval();
        }
        public override VT Parse(int i){
            var t = tlst[i];
            if(state == State.Begin){
                state = State.Mid;
                if(t.type == Token.L) return ParseGroup(i);
                if(t.type == Token.Num) return ParseNum(i);
                return (i + 1, Error);
            }
            if(state == State.Mid){
                var tk = tlst[i];
                if(tk.type == Token.P || tk.type == Token.M){
                    var left = children[0];
                    var ts = new TwoSync();
                    ts.tk = tk;
                    ts.children.Add(left);
                    ts.parent = this;
                    children[0] = ts;
                    return (i + 1, ts);
                }else if(tk.type == Token.R) {
                    return (i, parent);
                }
            }
            return (i + 1, Error);
        }
    }
    class TwoSync : Syntax{
        public TokenV tk;
        //ReadRightExp
        enum State {
            Begin,
            Mid,
        }
        public override int Eval(){
            var l = children[0].Eval();
            var r = children[1].Eval();
            if(tk.type == Token.P) return l + r;
            return l - r;
        }
        State state = State.Begin;
        public override VT Parse(int i){
            var tk = tlst[i];
            if (state == State.Begin)
            {
                state = State.Mid;
                if (tk.type == Token.L)
                {
                    // return ParseExp(i);
                    return ParseGroup(i);
                }
                if (tk.type == Token.Num)
                {
                    return ParseNum(i);
                }
                return (i + 1, Error);
            }
            //结束解析返回Exp
            return (i, parent);
        }
    }

    class GroupSync : Syntax{
        enum State {
            Begin,
            Mid,
            End,
        }
        private State state = State.Begin;
        public override VT Parse(int i){
            if(state == State.Begin){
                //(Exp)
                state = State.Mid;
                return ParseExp(i);
            }
            var t = tlst[i];
            if(t.type == Token.R){
                return (i + 1, parent);
            }
            return (i + 1, Error);
        }
    }
    static List<TokenV> tlst;
    public class Syntax{
        public Syntax parent;
        public List<Syntax> children = new List<Syntax>();
        public static Syntax Error = new Syntax();

        public virtual VT Parse(int i){
            return ParseExp(i);
        }
        public VT ParseNum(int i){
            var ns = new NumSync();
            children.Add(ns);
            ns.parent = this;
            return (i, ns);
        }
        //(Exp)
        public VT ParseGroup(int i){
           var g = new GroupSync();
            children.Add(g);
            g.parent = this;
            return (i+1, g); 
        }
        public VT ParseExp(int i){
            var t = tlst[i];
            if(t.type == Token.L){
                // var g = new GroupSync();
                // children.Add(g);
                // g.parent = this;
                // return (i+1, g);
                var exp = new ExpSync();
                children.Add(exp);
                exp.parent = this;
                return (i, exp); 
            }
            if(t.type == Token.Num){
                var exp = new ExpSync();
                children.Add(exp);
                exp.parent = this;
                return (i, exp);
            }
            return (i + 1, Error);
        }
        public virtual int Eval(){
            if(children.Count > 0) return children[0].Eval();
            return Int32.MinValue;
        }
    }
    public int Calculate(string s) {
        var lst = new List<TokenV>();
        tlst = lst;
        foreach(var c in s){
            if(c == ' '){

            }else if(c == '('){
                var tk = new TokenV()
                {
                    type = Token.L,
                };
                lst.Add(tk);
            }else if(c == ')'){
                var tk = new TokenV() { type = Token.R, };
                lst.Add(tk);
            }else if(c =='+'){
               var tk = new TokenV() { type = Token.P, };
                lst.Add(tk); 
            }else if(c == '-'){
               var tk = new TokenV() { type = Token.M, };
                lst.Add(tk);  
            }else if(c >= '0' && c <= '9'){
               var tk = new TokenV() { type = Token.Num, c = Convert.ToInt32(c.ToString()) };
                lst.Add(tk);   
            }
        }
        var root = new Syntax();
        var curNode = root;
        for (var i = 0; i < lst.Count; ){
            // Console.WriteLine("curN:" + curNode+":"+i);
            var rt = curNode.Parse(i);
            i = rt.Item1;
            curNode = rt.Item2;
        }
        return curNode.Eval();
    }
    // static void Main(string[] arg)
    // {
    //     var c = new Calc();
    //     // var r = c.Calculate("1 + 1");
    //     // var r = c.Calculate("2-1 + 2");
    //     // var r = c.Calculate("(1+(4+5+2)-3)+(6+8)");
    //     var r = c.Calculate("(1-((1 + 1)+(1-69)))");
    //     Console.WriteLine(r);
    // }
}
public class Solution {
    public int Calculate(string s) {
        var c = new Calc();
        return c.Calculate(s);
    }
}
```