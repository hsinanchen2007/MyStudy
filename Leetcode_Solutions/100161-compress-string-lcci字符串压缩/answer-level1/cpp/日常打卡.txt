### 解题思路
顺着思路来的 a=a+to_string(cnt)会超出内存限制
![image.png](https://pic.leetcode-cn.com/199de9990756097e6f7c6b4a2856941f449fe35503797af2a5fb5a0a257edcf5-image.png)

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string a;
        int cnt=1;
        for(int i=0;i<S.size();i++)
        {
            if(i==0)
            {
                a.push_back(S[0]);
                continue;
            } 
            else if(S[i-1]==S[i])
            {
                cnt++;
                
            }
            else if(S[i-1]!=S[i])
            {
                a+=to_string(cnt);
                cnt=1;
                a.push_back(S[i]);
            }
            if(i==S.size()-1) a+=to_string(cnt);
        }
        string ans=a.size()<S.size()?a:S;
        return ans;
    }
};
```