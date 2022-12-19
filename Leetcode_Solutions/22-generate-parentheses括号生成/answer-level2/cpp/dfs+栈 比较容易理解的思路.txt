### 解题思路
用一个栈记录还未配对的左括号

### 代码

```cpp
class Solution {
public:

    stack<char> s;
    vector<string> ans;
    int m;
    vector<string> generateParenthesis(int n) {
        m=n;
        dfs(n,n,"");
        return ans;
    }


    void dfs(int left,int right,string res){
        
        //(括号没有了，此时已经走到尽头
        if(left==0){
            //剩下的)不够补足还未配对的(
            if(right<s.size()) return;
            for(int i=0;i<right;i++){
                res=res+')';
            }
            ans.push_back(res);
            return;
        }
        else{
            //添加一个(
            s.push('(');
            dfs(left-1,right,res+'(');
            //注意
            s.pop();
        }
        if(right==0){
            if(left!=0){
                return;
            }
        }
        else{
            if(!s.empty()){
                //添加一个)
                s.pop();
                dfs(left,right-1,res+')');
                //注意
                s.push('(');
            }
            else{
                return;
            }
        }
    }
};
```