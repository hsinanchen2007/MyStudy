```
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> m;
        int n=barcodes.size();
        for(int i=0;i<n;++i)
        {
            m[barcodes[i]]++;
        }

        map<int,int>::iterator itmax=m.begin();
        for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
        {
            if(itmax->second<it->second)
            {
                itmax=it;
            }
        }

        int n2=n/2;
        int n1=n-n2;

        vector<int> res(n);
        
        int idx1=0;
        int idx2=0;

        while(itmax->second)
        {
            res[(idx1++)*2]=itmax->first;
            itmax->second--;
        }

        for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
        {
            while(idx1<n1 && it->second)
            {
                res[(idx1++)*2]=it->first;
                it->second--;
            }

            while(idx2<n2 && it->second)
            {
                res[(idx2++)*2+1]=it->first;
                it->second--;
            }
        }
        return res;
    }
};
```
