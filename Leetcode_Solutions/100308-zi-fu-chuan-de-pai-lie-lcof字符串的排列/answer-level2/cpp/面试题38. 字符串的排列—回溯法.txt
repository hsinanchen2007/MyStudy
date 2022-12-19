方法一 
一个布尔数组visited，初始化的时候都为 false 表示这些数还没有被选择，当我们选定一个数的时候，就将这个数组的相应位置设置为true。 
当s[i-1] == s[i]时，若确定当前位为s[i-1]，下一位为s[i]，在下一次将当前位确定为s[i]时，s[i-1]会被撤销选择, 即s[i-1]当前未被使用，那么确定下一位时可能出现s[i-1]，由于s[i-1] == s[i]，s[i-1]、s[i]和s[i]、s[i-1]是一样的。
因此需要去重，即当s[i-1] == s[i] && !visited[i-1]当前循环停止直接进入下次循环。
```
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        vector<bool> visited(s.size(), false);
        string tmp="";
        helper(s, 0, res, tmp, visited);
        return res;
    }
    void helper(string s,int level, vector<string>& res, string tmp, vector<bool>& visited){
        if(level == s.size()){
            res.push_back(tmp);
            return ;
        }
        for(int i = 0; i < s.size(); ++i){ 
            if(visited[i]|| (i>=1 && s[i-1] == s[i] && !visited[i-1])) continue;
            visited[i] = true;
            tmp +=s[i];
            helper(s, level+1, res, tmp, visited);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};
```
```
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        vector<bool> visited(s.size(), false);
        helper(s, 0,res, s, visited);
        return res;
    }
    void helper(string s,int level, vector<string>& res, string tmp, vector<bool>& visited){
        if(level == s.size()){
            res.push_back(tmp);
            return ;
        }
        for(int i = 0; i < s.size(); ++i){
            if(visited[i]|| (i>=1 && s[i-1] == s[i] && !visited[i-1])) continue;
            visited[i] = true;
            tmp[level] = s[i];
            helper(s, level+1, res, tmp, visited);
            visited[i] = false;
        }
    }
};
```
方法二 交换swap()
```
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        helper(s,0,res);
        return res;
    }
    void helper(string s,int level,vector<string>& res){
        if(level==s.size()){
            res.emplace_back(s);
            return;
        }
        vector<bool> visited(128,false);  
        for(int i=level;i<s.size();i++){
            if(visited[s[i]]) continue;
            visited[s[i]]=true;
            swap(s[i],s[level]);
            helper(s,level+1,res);
            swap(s[i],s[level]);
        }
    }
};
```
```
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        helper(s,0,res);
        return res;
    }
    void helper(string s,int level,vector<string>& res){
        if(level==s.size()){
            res.emplace_back(s);
            return;
        }
        set<char> visited;  
        for(int i=level;i<s.size();i++){
            if(visited.count(s[i])) continue;
            visited.insert(s[i]);
            swap(s[i],s[level]);
            helper(s,level+1,res);
            swap(s[i],s[level]);
        }
    }
};
```

