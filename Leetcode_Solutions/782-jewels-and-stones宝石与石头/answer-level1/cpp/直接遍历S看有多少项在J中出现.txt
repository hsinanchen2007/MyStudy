### 解题思路
代码很好懂，不用解释

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int i;
        int count=0;
        for(i=0;i<S.length();i++)
        {
            if(J.find(S[i])==J.npos)
               continue;
            else
                count++;
        }
        
        return count;

        

        
    }
};
```