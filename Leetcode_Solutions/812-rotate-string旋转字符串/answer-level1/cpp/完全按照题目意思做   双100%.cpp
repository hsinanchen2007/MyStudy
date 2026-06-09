
### 代码

```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        
        if(A.empty() && B.empty())
        {
            return true;
        }
        
        for(int i=0;i<A.size();i++)
        {
            string temp(1,A[0]);
            A.erase(A.begin());
            A+=temp;
            if(A==B)
            {
                return true;
            }
        }
        
        return false;

    }
};
```