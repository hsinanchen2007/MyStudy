不多说了，直接贴代码吧
```
int cnt[501];
class Solution {
public:
    int findLucky(vector<int>& arr) {
        for(int i=1; i<=500; i++) cnt[i] = i;
        for(auto x: arr)
            cnt[x] --;
        for(int i=500; i>=1; i--){
            if(cnt[i]==0) return i;
        }
        return -1;
    }
};
```
