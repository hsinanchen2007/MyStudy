```
vector<string>re;
void dfs(int n,int l,int r,string s) {
    if(r == n){
        re.push_back(s);
        return;
    }else if(l == n){
        dfs(n,l,r+1,s+')');
    }else{
        dfs(n,l+1,r,s+'(');
        if(l>r)dfs(n,l,r+1,s+')');
    }
    
}
vector<string> generateParenthesis(int n) {
    string s = "";
    dfs(n,0,0,s);
    return re;
}
```
