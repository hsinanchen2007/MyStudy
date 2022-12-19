### 解题思路
Root->Concate-->Union{Concate, Concate, Concate}
通过建立虚拟节点 Concate
保证解析简单性

LL(1)文法，带index 停滞

### 代码

```csharp
using VT = System.ValueTuple<int, RegAst>;
using ST = System.ValueTuple<int, System.Collections.Generic.List<string>>;
enum RegTType{
    Left,
    Right,
    Char,
    Comma,
}
class RegToken{
    public RegTType type;
    public string c;
}

enum RegAstType{
    Root,
    OneChar,
    Error,
    Con,
    Union,
}
class UnionAst : RegAst{
    enum State{
        Left,
        Exp,
        WaitComma,
    }
    public UnionAst(){
        type = RegAstType.Union;
    }
    State state = State.Exp;
    bool first = true;
    public override VT Parse(int i, List<RegToken> tokens){
        if(state == State.Exp){
            if (first)
            {
                first = false;
                var con = new ConcateAst();
                children.Add(con);
                con.parent = this;
                // return ParseExp(i, tokens);
                return (i, con);
            }else {
                var tk = tokens[i];
                if(tk.type == RegTType.Right){ //结束自己
                    return (i + 1, parent);
                }
                if(tk.type == RegTType.Comma){//开始下一个孩子表达式
                    var con = new ConcateAst();
                    children.Add(con);
                    con.parent = this;
                    // return ParseExp(i + 1, tokens);
                    return (i + 1, con);
                }
                return (i + 1, error);
            }
        }
        return (i + 1, error);
    }
    public override List<string> Eval(){
        var hs = new HashSet<string>();
        foreach(var c in children){
            // hs.Add(c.Eval());
            foreach(var s in c.Eval()){
                hs.Add(s);
            }
        }
        //A || B
        return hs.ToList();
    }
}
class ConcateAst : RegAst{
    //eachSubExp
    bool first = true;
    public ConcateAst(){
        type = RegAstType.Con;
    }
    public override VT Parse(int i, List<RegToken> tokens){
        if(first){
            first = false;
            return ParseExp(i, tokens);
        }else {
            //上一层结束
            var tk = tokens[i];
            if(tk.type == RegTType.Right) return (i, parent);
            if(tk.type == RegTType.Comma) return (i, parent);//父亲继续下一个内部表达式
            //{ 或者 Char
            return ParseExp(i, tokens);
        }
        return (i+1, error);
    }
    public override List<string> Eval(){
        var listSet = new List<List<string>>();
        foreach(var c in children){
            var set = c.Eval();
            listSet.Add(set);
        }
        var ret = new List<string>();
        //n*m*k 深度优先搜索
        var openQ = new Queue<ST>();
        openQ.Enqueue((0, new List<string>()));
        while(openQ.Count > 0){
            var fir = openQ.Dequeue();
            if(fir.Item1 >= listSet.Count) {
                ret.Add(String.Join("", fir.Item2.ToArray()));
                continue;
            }
            var next = listSet[fir.Item1];
            foreach(var c in next){
                var nst = new List<string>();
                nst.AddRange(fir.Item2);
                nst.Add(c);
                openQ.Enqueue((fir.Item1 + 1, nst));
            }
        }
        return ret;
    }
}
//深度遍历解析
//根 左右
class RegAst{
    public RegAstType type = RegAstType.Root;
    public RegToken token;
    public List<RegAst> children = new List<RegAst>();
    public RegAst parent;
    public static RegAst error = new RegAst()
    {
        type = RegAstType.Error,
    };
    public virtual List<string> Eval(){
        if(type == RegAstType.Root) return children[0].Eval();
        if(type == RegAstType.OneChar) return new List<string>() { token.c };
        return null;
    }
    //临时中间增加一层
    //Root-> a 
    public VT ParseExp(int i, List<RegToken> tokens){
        var tk = tokens[i];
        // var hasOneChild = false;
        // hasOneChild = children.Count > 0;
        // var isConcate = this.GetType() == typeof(ConcateAst);
        // if(!isConcate){
        //     var con = new ConcateAst();
        //     children.Add(con);
        //     con.parent = this;
        // }
        if(tk.type == RegTType.Left){
            var un = new UnionAst();
            children.Add(un);
            un.parent = this;
            // un.type = RegAstType.Exp;
            return (i + 1, un);
        }
        if(tk.type == RegTType.Char){
            var ast = new RegAst();
            ast.type = RegAstType.OneChar;
            ast.token = tk;
            ast.parent = this;
            children.Add(ast);
            return (i + 1, this);
        }
        //当前表达式结束 parent来处理 Finish逻辑
        if(tk.type == RegTType.Right){
            return (i, parent);
        }
        //Parent处理新增逻辑
        if(tk.type == RegTType.Comma) {
            return (i, parent);
        }
        return (i + 1, error);
    }
    public virtual VT Parse(int i, List<RegToken> tokens){
        var con = new ConcateAst();
        children.Add(con);
        con.parent = this;
        // return ParseExp(i, tokens);
        return (i, con);
    }
}
class RegSimple{
    public IList<string> BraceExpansionII(string expression) {
        var listTok = new List<RegToken>();
        for (var i = 0; i < expression.Length; i++){
            var c = expression[i];
            RegToken tk = null;
            if(c == '{'){
                tk = new RegToken(){ type = RegTType.Left,};
            }else if(c == '}'){
                tk = new RegToken(){ type = RegTType.Right,};
            }else if(c == ','){
                tk = new RegToken(){ type = RegTType.Comma,};
            }else if(c >= 'a' && c <= 'z'){
                tk = new RegToken(){ type = RegTType.Char, c = c.ToString(),};
            }
            if(tk != null) listTok.Add(tk);
        }

        var rootNode = new RegAst() { type = RegAstType.Root };
        var curNode = rootNode;
        for (var i = 0; i < listTok.Count;)
        {
            var tk = listTok[i];
            //Console.WriteLine("Parse:"+i+":"+tk.type+":"+tk.c+":"+curNode.type+":"+curNode.children.Count);
            var r = curNode.Parse(i, listTok);
            i = r.Item1;
            curNode = r.Item2;
            if(i < listTok.Count) tk = listTok[i];
            //Console.WriteLine("Ret:"+i+":"+tk.type+":"+tk.c+":"+curNode.type+":"+curNode.children.Count);
        }
        var ret = rootNode.Eval();
        ret.Sort();
        return ret;
    }
}

public class Solution {
    public IList<string> BraceExpansionII(string expression) {
        var rs = new RegSimple();
        return rs.BraceExpansionII(expression);
    }
}
```