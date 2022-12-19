```
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> resh, resm;
        vector<string> res;
        char buf[32];
        for(int i=0; i<=min(3, num); i++)
        {
            resh.clear();
            resm.clear();
            getNum(12, i, 4, 0, resh);
            getNum(60, num-i, 6, 0, resm);
            for(auto h:resh)
            {
                for(auto m:resm)
                {
                    sprintf(buf, "%d:%02d", h, m);
                    res.push_back(buf);
                }
            }
        }
        
        return res;
    }
    void getNum(int mx, int num, int len, int h, vector<int>& res)
    {
        if(len == 0)
        {
            if(h<mx)
                res.push_back(h);
            return;
        }
        if(len>num)
        {
            getNum(mx, num, len-1, h<<1, res);
        }
        if(num>0)
        {
            getNum(mx, num-1, len-1, (h<<1)+1, res);
        }
    }
};
```
