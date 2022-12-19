```
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = int(sqrt(area));
        int W = L;
        vector<int> res;
        if(L * W == area)
        {
            res.push_back(L);
            res.push_back(W);
            return res;
        }
        while(W>=1 && L<=area)
        {
            if(L * W < area)
            {
                L++;
            }
            else if(L * W > area)
            {
                W--;
            }
            else
            {
                res.push_back(L);
                res.push_back(W);
                break;
            }
        }
        return res;
    }
};
```