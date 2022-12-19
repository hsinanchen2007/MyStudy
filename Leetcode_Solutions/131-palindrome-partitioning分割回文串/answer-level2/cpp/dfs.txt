### 解题思路
从长度为1的字串开始检查，字串长度每次加一，如果该字串是回文串，则加入当前答案。
判断到母串的最后一个位置后则当前答案就是一个答案。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>>res;
    int len;
    bool check(string& s){ //判断回文
        int i=0,j=s.size()-1;
        if(!j)return true;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++,j--;
        }
        return true;
    }
    void dfs(string& s,int start,vector<string>&current){
        if(start>=len)res.push_back(current);
        for(int i=start;i<len;i++){ 
            string t = s.substr(start,i-start+1); //子串长度为i-start+1 从1~len-start
            if(check(t)){
                current.push_back(t);
                dfs(s,i+1,current);//判断下一个从i+1开始的字串
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string& s) {
        int n = s.size();
        len = n;
        if(!n)return res;
        vector<string>current;
        dfs(s,0,current);
        return res;

    }
};
```