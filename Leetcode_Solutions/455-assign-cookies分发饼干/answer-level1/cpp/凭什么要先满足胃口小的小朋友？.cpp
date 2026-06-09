从胃口大的小朋友先开始满足，一样可以获得最优解！
```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        for(int i=g.size()-1,j=s.size()-1;i>=0&&j>=0;--i)
            if(g[i]<=s[j]){
                --j;
                ++count;
            }
        return count;
    }
};
```