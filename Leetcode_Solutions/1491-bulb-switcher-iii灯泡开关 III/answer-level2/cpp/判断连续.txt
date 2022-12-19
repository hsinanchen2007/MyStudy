只要简单记录最大的亮灯编号等于总亮灯数即可
```
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0, count = 0, maxi = 0;
        for(int i = 0; i < light.size(); i++) {
            maxi = max(maxi, light[i]);
            count++;
            if(maxi == count) ans++;
        }
        return ans;
    }
};
```
