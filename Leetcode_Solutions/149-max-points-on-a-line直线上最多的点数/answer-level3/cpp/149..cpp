维护以某i点开始能经过的最多点(不算点i)
而不是维护斜率k能经过哪些点.
这样重复点的问题就好解决了->维护起点的个数col
用unordered_map能做到复杂度O(n2)
```
class Solution {
public:
  
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)return points.size();
        map<long long,int>mp;int ans=0;
        //cout<<__gcd(0,5);
        for(int i=0;i<points.size();i++){//此点为起点
            mp.clear();int col=1;int tp=0;
            for(int j=i+1;j<points.size();j++){
                int dely=points[j][1]-points[i][1];
                int delx=points[j][0]-points[i][0];
                if(delx==0&&dely==0){
                    col++;
                    continue;
                }
                int gcd=__gcd(delx,dely);
                dely=dely/gcd;
                delx=delx/gcd;
                long long hash=1ll*delx*1000000+dely;
                //cout<<delx<<" "<<dely<<" "<<hash<<endl;
                if(mp.count(hash)==0){
                    mp[hash]=1;tp=max(tp,mp[hash]);
                }
                else{
                    mp[hash]++;
                    tp=max(tp,mp[hash]);
                } 
            }
            ans=max(ans,tp+col);
        }
       
        return ans;
    }
};
```