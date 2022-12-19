```
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> min_len(S.size(), 20000);
        int index1 = -20000;
        int index2 = -1;
        int i = 0;
        index2 = S.find(C);
        while(i<S.size())
        {
            min_len[i] = min(i-index1, index2-i);
            if(i==index2)
            {
                index1 = index2;
                index2 = S.find(C, index2+1);
                if(index2 == -1)
                {
                    index2 = 20000;
                }
            }
            i++;
        }
        return min_len;
    }
};
```
