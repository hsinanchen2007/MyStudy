```
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int ii = (x==1?0:int(log(bound)/log(x))+1), jj = (y==1?0:int(log(bound)/log(y))+1);
        set<int> tmp;
        for(int i=0;i<=ii;i++)
        {
            for(int j=0;j<=jj;j++)
            {
                if(pow(x,i) + pow(y,j) <= bound)
                    tmp.insert(pow(x,i) + pow(y,j));
            }
        }
        vector<int> res(tmp.begin(),tmp.end());
        return res;
    }
};
```