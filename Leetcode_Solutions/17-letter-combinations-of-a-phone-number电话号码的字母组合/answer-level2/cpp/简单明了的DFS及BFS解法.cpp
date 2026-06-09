简单DFS如下
```
    void DFS(string digits,string curr,int layer){
        if(layer == digits.size())
            res.push_back(curr);
        else
            for(int i=0;i<mp[digits[layer]].size();i++)
                DFS(digits,curr + mp[digits[layer]][i],layer+1); 
    }
```
BFS稍微复杂点，但是容易理解
```
    void BFS(string digits){
        queue<string> q;
        for(int i=0;i<mp[digits[0]].size();i++){
            //坑爹的string单个元素是char不能直接赋给string
            string tmp;
            tmp+=mp[digits[0]][i];
            q.push(tmp);
        }

        for(int i=1;i<digits.size();i++){
            int len = q.size();
            while(len--){
                string a = q.front();
                for(int j=0;j<mp[digits[i]].size();j++)
                {
                    string tmp = a+mp[digits[i]][j];
                    q.push(tmp);
                }
                q.pop();
            }
        }
        while(!q.empty()){
            //vector不是append
            res.push_back(q.front());
            q.pop();
        }
    }
```
完整代码见下
```
class Solution {
public:
    unordered_map<char, string> mp = unordered_map<char, string>{
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};        
    vector<string> res;
    void BFS(string digits){
        ...
    }
    void DFS(string digits,string curr,int layer){
        ...
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return res;
        //BFS(digits);
        DFS(digits,"",0);
        return res;
    }
};
```

