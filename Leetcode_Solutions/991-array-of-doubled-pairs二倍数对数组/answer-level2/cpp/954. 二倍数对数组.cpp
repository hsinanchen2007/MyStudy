```
class Solution {
public:
    bool function(vector<int>& a)
    {
        int n=a.size();
        if(n%2)return false;
        if(n==0)return true;
        stable_sort(a.begin(),a.end());
        unordered_map<int,int> m;
        for(int i=0;i<n;++i)
        {
            m[a[i]]++;
        }
        
        for(int aa: a)
        {
            if(m[aa]!=0)
            {
                int aa2=aa*2;
                if(m[aa2])
                {
                    m[aa]--;
                    m[aa2]--;
                }
                else
                    return false;
            }
        }
        return true;
    }

    bool canReorderDoubled(vector<int>& A) {
        int n=A.size();
        if(n%2)return false;
        vector<int> positive,negative;
        int zerocounter=0;
        for(int i=0;i<n;++i)
        {
            int a=A[i];
            if(a>0)positive.emplace_back(a);
            else if(a<0)negative.emplace_back(-a);
            else ++zerocounter;
        }
        if(zerocounter%2)return false;
        if(!function(positive))return false;
        if(!function(negative))return false;
        return true;
    }
};
```
