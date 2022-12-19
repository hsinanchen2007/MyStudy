### 解题思路
esp判等，注意处理相同点。对相同点的处理可以进一步优化，不优化也能过。

### 代码

```cpp
class Solution {
public:
map<pair<double,double>,int> st;
vector<int> pp;
    double k;
    double b;
    int flag[10000];
    double esp=1e-8;
    int sgn(double a,double b){
        if(fabs(a-b)<esp)
            return 1;
        else return 0;
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        if(points.size()==1) return 1;
        memset(flag,0,sizeof(flag));
        vector<vector<int>> point;
        for(int i=0;i<points.size();i++){
            if(flag[i]) continue;
            for(int j=i+1;j<points.size();j++){
                if(points[i]==points[j]){
                    pp.push_back(j);
                    flag[j]++;
                }
            }
            point.push_back(points[i]);
        }
        //return point.size();
        if(point.size()==1) return points.size();
        for(int i=0;i<point.size();i++){
            for(int j=i+1;j<point.size();j++){
                if(point[j][1]!=point[i][1]&&point[j][0]==point[i][0]) {
                    k=point[i][0];
                    b=1e32;
                }
                else{

                k=(point[j][1]-point[i][1]+0.0)/(point[j][0]-point[i][0]+0.0);
                b=1.0*(point[j][1]-k*point[j][0]);
                }
                int flag=0;
                for(auto iter=st.begin();iter!=st.end();++iter){
                    if(sgn(iter->first.first,k)&&sgn(iter->first.second,b)){
                        flag=1;
                        iter->second++;
                        break;
                    }
                }
                if(flag==0) st[make_pair(k,b)]=1;
            }
        }
        int ans=1;
        pair<double,double> tem;
        for(auto iter=st.begin();iter!=st.end();++iter){
            iter->second=(1+sqrt(1+8*iter->second))/2;
            for(int i=0;i<pp.size();i++){
                int mm=pp[i];
                if(sgn(iter->first.first,points[mm][0])&&sgn(iter->first.second,1e32))
                    iter->second++;
                else{
                if(sgn(points[mm][1],(iter->first.first*points[mm][0]+iter->first.second)))
                    iter->second++;
                }
            }
        
            ans=ans>iter->second?ans:iter->second;
        }
        return ans;
    }

};
```