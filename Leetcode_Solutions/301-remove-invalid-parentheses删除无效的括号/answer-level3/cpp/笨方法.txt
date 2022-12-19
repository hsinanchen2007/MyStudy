### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    set<string> ans;
    int max1=0;
    vector<string> removeInvalidParentheses(string s) {
        string t="";
        remove(s,t,0,0,0);
        vector<string> ans1;
        for(auto it=ans.begin();it!=ans.end();it++){
            ans1.push_back(*it);
        }
        return ans1;
    }
    void remove(string s,string t,int begin,int left,int right){
        if(right>left){
            return;
        }
        if(left==right){
            if(max1==t.length()){
                ans.insert(t);
            }
            else if(max1<t.length()){
                ans.clear();
                ans.insert(t);
                max1=t.length();
            }
            if(begin==s.length())
                return;
        }
        for(int i=begin;i<s.length();i++){
            if(s[i]=='('){
                t+=s[i];
                remove(s,t,i+1,left+1,right);
                t=t.substr(0,t.length()-1);
            }
            else if(s[i]==')'){
                if(right+1<=left){
                    t+=s[i];
                    remove(s,t,i+1,left,right+1);
                    t=t.substr(0,t.length()-1);
                }
                else{
                    continue;
                }
            }
            else{
                t+=s[i];
                remove(s,t,i+1,left,right);
                t=t.substr(0,t.length()-1);
            }
        }
    }
};
```