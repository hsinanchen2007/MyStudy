

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        BackTrack(res,"",n,0);
        return res;
    }
    void BackTrack(vector<string>& res,string str,int left,int right)
    {
        if(left==0 && right==0)
        {
            res.push_back(str);
            return ;            
        }
        if(left>0)
            BackTrack(res,str+'(',left-1,right+1);//每次加一个'(',要保证之后会有')'，因此给之后需要的右括号的计数加1
        if(right > 0)
            BackTrack(res,str+')',left,right-1);
    }
};
```