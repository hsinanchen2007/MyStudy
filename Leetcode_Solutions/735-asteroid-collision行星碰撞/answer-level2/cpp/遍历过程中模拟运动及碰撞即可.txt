```
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> r;
        for(int a: asteroids){
            if(a>0){
                r.push_back(a);
                continue;
            }
            
            while(!r.empty() && r.back()>0 && r.back()+a<0) r.pop_back();
            if(r.empty() || r.back()<0) r.push_back(a);
            else if(r.back()+a==0) r.pop_back();
        }
        return r;
    }
};
```