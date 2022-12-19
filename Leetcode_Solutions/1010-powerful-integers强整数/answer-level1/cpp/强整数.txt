枚举 set去重， 0s通过，
```
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        int tempi = 1;
        for(int i = 0; tempi < bound; i++){
            int tempj = 1;
            for(int j = 0; tempj < bound; j++){
                int temp = tempi + tempj;
                if(temp <= bound) s.insert(temp);
                else break;
                if(y == 1) break;
                tempj *= y;
            }
            if(x == 1) break;
            tempi *= x;
        }
        vector<int> ans;
        for(auto a : s) ans.push_back(a);
        return ans;
    }
};
```
