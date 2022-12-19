### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> st1;
        vector<int> st2;
        vector<int> res(seq.size());
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                  st1.push('(');
                  st2.push_back(i);    
            }
            else
            {
              st1.pop();
              if(st2.size()%2)
              {
              res[st2.back()]=1;
              res[i]=1;
              st2.pop_back();
              }
              else
              {
              res[st2.back()]=0;
              res[i]=0;
              st2.pop_back();  
              }
 
            }

        }
        return res;
    }
};
```