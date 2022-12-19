### 解题思路
这道题我的思路是深度优先，加剪枝。
实际上我们只需要在生成对应序列的时候，严格控制）少于（，只需判断是否已经生成即可。
代码如下：
这种方法效率极低，5%左右。
### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> sequence{'('};
        vector<string> temp;
        int left=1,right=0;
        DFS(n,left,right,temp,sequence);
        return temp;
    }

    bool DFS(int n,int left,int right,vector<string> &result,vector<char> sequence){
        if(left==n){
            while(right<n){
                sequence.push_back(')');
                right++;
            }
            if(judge(sequence,result)){
                result.push_back(string(sequence.begin(),sequence.end()));
                return true;
            }else
                return false;
        }else{
            if(right>left)
                return false;
            else{
                sequence.push_back('(');
                DFS(n,left+1,right,result,sequence);
                sequence.pop_back();
                sequence.push_back(')');
                DFS(n,left,right+1,result,sequence);
            }
        }
        return true;
    }

    int judge(vector<char> currentsequence,vector<string> result){
        string s(currentsequence.begin(),currentsequence.end());
        for(int i=0;i<result.size();++i){
            if(result[i].compare(s)==0)
                return false;
        }
        return true;
    }
};
```