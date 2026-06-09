很多这种类型的题，都是套路了，一个模式。
即使用一个前缀和(积)来保存某i之前所有的状态累计，如此可以求任意两个状态之间的累计。

```cpp
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> lives(1001, 0), gos(1001,0);
        for(const int &val: birth) lives[val-1900]++;
        for(const int &val: death) gos[val-1900]++;
        for(int i = 1; i < 1001; i++) lives[i] = lives[i-1] + lives[i];
        for(int i = 1; i < 1001; i++) gos[i] = gos[i-1] + gos[i];
        int max_p = lives[0];
        int year = 0;
        for(int i = 1; i < 1001; i++){
            int p = lives[i] - gos[i-1];
            if(max_p < p){
                max_p = p;
                year = i;
            }
        }
        return 1900+year;
    }
};
```