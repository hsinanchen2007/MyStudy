执行用时52 ms,击败了32.95%；
内存消耗11.3 MB击败了100.00%
```
class Solution {
public:
    string removeDuplicates(string S) 
    {
        for (int i = 0; i < S.size(); i++)
        {   
            if(S[i]==S[i+1])
            {
                S.erase(S.begin()+i, S.begin()+i+2);
                i = i>=2 ? i-2 : -1;    
            }
        }
        return S;
    }
};
```
