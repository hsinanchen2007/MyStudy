暴力枚举子方阵上下行[l,r]，记A[i]为第i列matrix在[l,r]行值的或，那么问题又变为一维问题，即找一处i,使得第l行和第r行中，i到i+len-1列的值都是0，这个可以用前缀和判断，同时再满足!A[i] && !A[i+len-1]即可，其中len=r-l+1;
```
class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& A) {
        int len=0;
        vector<int> Ans;
        int n=A.size();
        if (!n) return Ans;
        int m=A[0].size();
        vector<int> Mark(m);
        vector<int> sum(m+1);
        int r,c;
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j) Mark[j]=0;
            for (int j=i;j<n;++j)
            {
                int tlen=j-i+1;
                for (int k=0;k<m;++k) Mark[k]|=A[j][k];
                if (tlen<len) continue;
                for (int k=0;k<m;++k)
                {
                    Mark[k]|=A[j][k];
                    sum[k+1]=sum[k];
                    if (A[i][k]) ++sum[k+1];
                    if (A[j][k]) ++sum[k+1];
                    if (k-tlen+1>=0)
                    {
                        if (!Mark[k-tlen+1] && !Mark[k])
                        {
                            if (sum[k+1]==sum[k-tlen+1])
                            {
                                if (tlen>len)
                                {
                                    len=tlen;
                                    r=i;
                                    c=k-tlen+1;
                                }
                                else if (tlen==len && (i<r || i==r && k-tlen+1<c))
                                {
                                    r=i;
                                    c=k-tlen+1;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (len)
        {
            Ans.push_back(r);
            Ans.push_back(c);
            Ans.push_back(len);
        }
        return Ans;
    }
};
```
