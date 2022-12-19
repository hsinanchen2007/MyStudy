### 解题思路
假设左括号是1，右括号是6，那么我们从111666来当做第一个排列，然后求它的全排列，利用next_permutation函数，第一次提交AC，但是时间只有24ms，很慢，然后我们思考剪枝，不难发现如果第一个数位6的时候那一定之后的都不合法，所以break掉，击败74.77%用户，当然这题还能优化，不过我就把我能在五分钟内思考并完成的算法发出来了，我觉得这才是可能在面试中能发挥的水平，不喜勿喷。

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0)
            return ans;
        string s = "";
        for(int i=0;i<n;++i)
            s+="(";
        for(int i=0;i<n;++i)
            s+=")";
        do{
            if(s[0]==')')
                break;
            if(isOrder(s))
                ans.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
    bool isOrder(string str){
        stack<char>s;
        for(int i=0,len=str.size();i<len;++i){
            if(str[i]=='(')
                s.push(str[i]);
            else{
                if(!s.size())
                    return false;
                s.pop();
            }
        }
        if(s.size())
            return false;
        return true;
    }
};
```