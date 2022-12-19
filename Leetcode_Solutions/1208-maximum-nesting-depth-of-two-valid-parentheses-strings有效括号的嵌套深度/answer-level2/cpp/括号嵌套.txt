### 解题思路
注意要使得分成的两部分嵌套深度最小要使得max(depth(A),depth(B)取值最小)，而不是简单将括号分为两部分。
以()(()())为例，每个位置的嵌套深度分别为1,1,1,2,2,2,2,1,要使得嵌套深度小，那么将嵌套深度为1和2的有效括号对半分即可。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //要使得max(depth(A),depth(B)取值最小)
        vector<int>res;
      int depth=0;
        int n=seq.length();
        if(n<=0)
        return res;
        for(int i=0;i<n;i++)
        {
            char c=seq[i];
            if(c=='(')   //如果是左括号，则嵌套深度加加
            {
                depth++;
                res.push_back(depth%2);
            }
            else
            {
                  res.push_back(depth%2);
                depth--;
              
            }
        }
       
       return res;

       

    }
};
```