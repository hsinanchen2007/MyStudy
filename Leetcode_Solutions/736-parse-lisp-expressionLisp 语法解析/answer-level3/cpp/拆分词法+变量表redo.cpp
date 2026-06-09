
萌新第一次写题解，提供一个c++的做法。|･ω･｀)

先用getTokens(expr)把expr拆成词法块（这里要注意的是'('和')'之间的算一个词法块），然后递归解决。
考虑到每层拷贝变量的复杂度，这里每一层的变量变化用一个globvar记录，然后在这一层分析结束的时候把这层对全局变量表var做的改变再改回来。必须在这层分析结束的时候做是因为这层的变量改变是可以应用到同层或者下一层的。

```
class Solution {
public:
    map<string, int> var;
    int inf = 1 << 30;

    //getTokens 作用： 
    //(let x 2 (add x 2)) -> ["let", "x", "2", "(add x 2)"]  
    void getTokens(string e, vector<string>& res){
        int cnt = 0, start = 0;
        if(e[0] == '('){ start = 1; }
        for(int i = start; i < e.size(); i++){
            if(cnt == 0 && (e[i] == ' ' || e[i] == ')')){ 
                res.emplace_back(e.substr(start, i - start));
                start = i + 1;
            }
            
            if(e[i] == '('){ cnt += 1; }
            else if(e[i] == ')'){ cnt -= 1; }
        }
    }

    int evaluate(string expression) {
        map<string, int> globvar;
        vector<string> tokens;
        getTokens(expression, tokens);        
        string cmd = tokens[0];
        int res = 0;
        
        if(cmd == "let"){
            int i = 1;
            //更新变量表
            for( ; i + 1 < tokens.size(); i += 2){
                string v1 = tokens[i], e1 = tokens[i + 1];
                //globvar记录局部更新的变量表
                if(globvar.find(v1) == globvar.end()){
                    if(var.find(v1) != var.end()){
                        globvar[v1] = var[v1];
                    }
                    else { globvar[v1] = inf; }
                }
                if(e1[0] == '('){
                    var[v1] = evaluate(e1);
                }
                else if(e1[0] >= '0' && e1[0] <= '9' || e1.size() >= 2 && e1[1] >= '0' && e1[1] <= '9'){ var[v1] = stoi(e1); }
                else { var[v1] = var[e1]; }
            }
            //通过更新过的var变量表递归计算expression的值
            string expr = tokens[i];
            if(expr[0] == '('){
                res = evaluate(expr);
            }
            else {
                if(var.find(expr) != var.end()){ res = var[expr]; }
                else { res = stoi(expr); }
            }
        }
        else if(cmd == "add" || cmd == "mult"){
            string v1 = tokens[1], v2 = tokens[2];
            int vint1, vint2;
            //递归计算值
            if(v1[0] == '('){ vint1 = evaluate(v1); }
            else {
                if(var.find(v1) != var.end()) { vint1 = var[v1]; }
                else { vint1 = stoi(v1); }
            }
            if(v2[0] == '('){ vint2 = evaluate(v2); }
            else {
                if(var.find(v2) != var.end()) { vint2 = var[v2]; }
                else { vint2 = stoi(v2); }
            }
            if(cmd == "add") { res = vint1 + vint2; }
            else if(cmd == "mult") { res = vint1 * vint2; }
        }
        //redo var变量表，消除局部变量的影响，inf代表这个变量本来不存在，erase即可
        for(auto it = globvar.begin(); it != globvar.end(); it++){
            if(it->second == inf){ var.erase(it->first); }
            else{ var[it->first] = it->second; }
        }
        
        return res;
    }
};
```
