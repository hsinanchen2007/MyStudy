```
class Solution {
public:
    int nthUglyNumber(int n) {
        int vec[n]{1};

        int id[3]{0,0,0};
        int v[3]{2,3,5};
        const int tmp[3]{2,3,5};

        int cnt=1;

        while(cnt<n)
        {
            int t_id=0;
            if(v[t_id]>v[1])
            {
                t_id=1;
            }
            else if(v[t_id]==v[1])
            {
                v[1]=vec[++id[1]]*tmp[1];
            }
            if(v[t_id]>v[2])
            {
                t_id=2;
            }
            else if(v[t_id]==v[2])
            {
                v[2]=vec[++id[2]]*tmp[2];
            }

            vec[cnt++]=v[t_id];

            v[t_id]=vec[++id[t_id]]*tmp[t_id];
        }

        return vec[n-1];
    }
};
```
