
将s和g按从小到大排序，然后分发饼干
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        int gi=0,si=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(gi<g.size() && si<s.size()){
            if(s[si]>=g[gi]){
                count++;
                si++;
                gi++;
            }
            else if(s[si]<g[gi])
            si++;
        }
        return count;
    }
};

```