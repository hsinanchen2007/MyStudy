```
class Solution {
public:
          int gcd(int dy,int dx){
              if(dx==0) return dy;
              else
                    return gcd(dx,dy%dx);
          }

    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int res=0;
       
        for(int i=0;i<n-1;i++){
             map<string,int>mp;
             int repeat=0;
             int tmp_max=0;
             for(int j=i+1;j<n;j++){
                 int dy=points[i][1]-points[j][1];
                 int dx=points[i][0]-points[j][0];
                 if(dx==0&&dy==0){
                     repeat++;
                     continue;
                 }
                 int g=gcd(dx,dy);
                 if(g!=0){
                     dy/=g;
                     dx/=g;
                 }
                 string temp=to_string(dy)+"/"+to_string(dx);
                 mp[temp]++;
                 tmp_max=max(tmp_max,mp[temp]);
             }
             res=max(res,repeat+tmp_max+1);
        }    
        return res;
    }
};
```
