```
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        if(light.empty()) return 0;
        int res = 0;
        int l = light.size();
        long s = 0;
        for(int i=0; i<l; i++){
            s += light[i];
            if(s == (long(1+i+1))*(long(i+1))/2) res++;
        }
        return res;
    }
};
```
