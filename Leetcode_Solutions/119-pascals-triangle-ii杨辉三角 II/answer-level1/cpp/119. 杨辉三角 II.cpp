```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex+1;
        vector<int> res(n,1);
        if(rowIndex>0)
        {
            int n2=(rowIndex>>1)+1;
            for(int i=1;i<=n2;++i)
            {
                res[i]=(int)((long)res[i-1]*(n-i)/i);
                res[rowIndex-i]=res[i];
            }
        }
        return res;
    }
};
```
