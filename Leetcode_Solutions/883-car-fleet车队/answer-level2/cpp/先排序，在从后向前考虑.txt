```
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> v;
        if(position.size()<=1)return position.size();
        for(int i=0;i<position.size();++i){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),[](const vector<int>& v1,const vector<int>& v2){
            return v1[0]<v2[0];
        });
        vector<float> vd;
        for(int i=0;i<position.size();++i){
            vd.push_back((float)(target-v[i][0])/v[i][1]);
        }
        float temp=vd[position.size()-1];
        int ans=1;
        for(int i=position.size()-2;i>=0;--i){
            if(vd[i]<=temp){
                vd[i]=temp;
            }
            else{
                temp=vd[i];
                ++ans;
            }
            
        }
        return ans;
    }
};
```
