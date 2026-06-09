### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    vector<string> v1,ans;
    //string s1;
public:
    vector<string> generateParenthesis(int n) {
        string s1;
        generate(0,0,n,s1);
        //cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();++i){
            if(isRight(v1[i])){
                ans.push_back(v1[i]);
               // cout<<v1[i]<<endl;
            }
        }
        return ans;
    }
    bool isRight(string str){
        stack<char> s;
        for(int i=0;i<str.length();++i){
            if(str[i]=='('){
                s.push(str[i]);
            }else if(str[i]==')'){
                if(!s.empty()&&s.top()=='('){
                    s.pop();
                }else{
                    return false;
                }
            }
        }
        return s.empty();
    }
    void generate(int n,int m,int sum,string s1){
        if(n==m&&m==sum){
           // cout<<s1<<endl;
            v1.push_back(s1);
            s1.clear();
        }
        if(s1.length()>2*sum) {
            s1.clear();
            return ;
        }
        if(n>sum||m>sum) {
            s1.clear();
            return ;
        }
        generate(n+1,m,sum,s1+"(");
        generate(n,m+1,sum,s1+")");


    }
};
```