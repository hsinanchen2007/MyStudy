### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length())
            return false;
        else
        {
            vector<int> diff;
            set<int> AA;
            for(int i=0;i<A.length();i++)
            {
                if(A[i]!=B[i])
                    diff.push_back(i);
                AA.insert(A[i]);
            }
            if(diff.empty()&&A.length()-AA.size()>0)
                return true;
            else if(diff.size()!=2)
                return false;
            else
            {
                if(A[diff[0]]==B[diff[1]]&&A[diff[1]]==B[diff[0]])
                    return true;
                else
                    return false;
            }
        }
    }
};
```