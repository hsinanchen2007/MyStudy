```
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size())
        {
            return false;
        }
        if(A.size() == 0)
        {
            return true;
        }
        int i = -1;
        string roate;
        while((i = A.find(B[0], i+1)) > 0)
        {
            roate = A.substr(i) + A.substr(0, i);
            if(roate == B)
            {
                return true;
            }
        }
        return false;
    }
};
```
