```
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> vx,vy;
        if(x==1)
        {
            vx.emplace_back(1);
        }
        else
        {
            vx.reserve(17);
            int i=1;
            while(i<bound)
            {
                vx.emplace_back(i);
                i*=x;
            }
        }

        if(y==1)
        {
            vy.emplace_back(1);
        }
        else
        {
            int i=1;
            while(i<bound)
            {
                vy.reserve(17);
                vy.emplace_back(i);
                i*=y;
            }
        }

        int nx=vx.size(),ny=vy.size();
        unordered_set<int> res;
        for(int i=0;i<nx;++i)
        {
            for(int j=0;j<ny;++j)
            {
                int tmp=vx[i]+vy[j];
                if(tmp<=bound)
                {
                    res.insert(tmp);
                }
                else
                {
                    break;
                }
            }
        }

        vector<int> ret;
        std::copy(res.begin(), res.end(), std::back_inserter(ret));

        return ret;
    }
};
```
