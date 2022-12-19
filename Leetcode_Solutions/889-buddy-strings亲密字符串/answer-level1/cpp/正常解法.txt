

### 代码

```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()) return false;
        if(A.empty()&&B.empty()) return false;

        if(A==B)
        {
            unordered_map<char,int> m;
            for(char a:A) m[a]++;
            for(auto u:m) if(u.second>=2) return true;
            return false; 
        }

        else
        {
            vector<int> help;
            for(int i=0;i<A.size();i++)
                if(A[i]!=B[i]) help.push_back(i);
            if(help.size()==2)  
                if(A[help[0]]==B[help[1]]&&A[help[1]]==B[help[0]]) 
                    return true;
            return false;
        }

        return true;
    }
};
```