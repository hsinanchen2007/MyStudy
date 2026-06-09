**数学解法o(n^2)思路：以i为中心，分别统计左右两边大于、小于rating[i]的数目，最后通过相乘求和。**
```
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt=0;
        int n = rating.size();
        int lmin, lmax, rmin, rmax;
        for(int i=0;i<n;++i){
            lmin=0;lmax=0;rmin=0;rmax=0;

            for(int j=0;j<i;++j){
                if(rating[j]<rating[i]) lmin++;
                else if(rating[j]>rating[i]) lmax++;
            }

            for(int j=i+1;j<n;++j){
                if(rating[j]<rating[i]) rmin++;
                else if(rating[j]>rating[i]) rmax++;
            }
            //printf("%d %d %d %d\n", lmin, lmax, rmin, rmax);

            cnt += lmin*rmax + lmax*rmin;
        }

        return cnt;
    }
};
```


**回溯解法o(n^3)思路：简单回溯解法**
```
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt=0;
        int n = rating.size();
        vector<int> rec;
        resolve(rating, cnt, rec, -1, 0);
        return cnt;
    }

    void resolve(vector<int> &rating, int &cnt, vector<int> &rec, int n, int num){
        if(num==3){
            if(rec[0]>rec[1]&&rec[1]>rec[2] || rec[0]<rec[1]&&rec[1]<rec[2]){
                cnt++;
            }
            //for(auto per:rec){
                //cout<<per<<" ";
            //}
            //cout<<endl;
            return;
        }

        for(int i=n+1;i<rating.size();++i){
            rec.push_back(rating[i]);
            resolve(rating, cnt, rec, i, num+1);
            rec.pop_back();
        }
    }
};
```

