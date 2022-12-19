```
inline bool cmp(vector<vector<int>>a,vector<vector<int>>b){
    return a[1]<a[2];
}
const int maxn=1e3+100;
class Solution {
public://我记得中科大的复试考的就是这一个题目。。。。
    bool solve(int a,int b,int num,int cost,vector<int>&ans){//solve只做判断，不进行加减操作。。。。
        for(int i=a;i<b;i++){
            if(ans[i]+num>cost)return false;
        }
        return true;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int m=trips.size();
        sort(trips.begin(),trips.end());
        vector<int>ans(maxn,0);
        for(int i=0;i<m;i++){
            int a=trips[i][1];
            int b=trips[i][2];
            int num=trips[i][0];
            if(!solve(a,b,num,capacity,ans))return false;
            for(int j=a;j<b;j++){
                ans[j]+=num;
            }
        }
        return true;
    }
};
```
