```
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& Seats) {
        int count = 0, line = 1, i = 0;
        map<int,bitset<11>> m;
        for(auto& st : Seats)
        {
            m[st[0]].set(st[1]);
        }
        bitset<11> b;
        for(auto& mi : m)
        {   
            b = mi.second;
            if(b.count() == 0 || (!b[2]&&!b[3]&&!b[4]&&!b[5]&&!b[6]&&!b[7]&&!b[8]&&!b[9]))
                count += 2;
            else if((!b[2]&&!b[3]&&!b[4]&&!b[5]) && (b[6]||b[7]||b[8]||b[9]))
                count += 1;
            else if((!b[6]&&!b[7]&&!b[8]&&!b[9]) && (b[2]||b[3]||b[4]||b[5]))
                count += 1;
            else if((!b[4]&&!b[5]&&!b[6]&&!b[7])&& (b[2]||b[3]) && (b[8]||b[9]))
                count += 1;
        }
        return count+2*(n-m.size());
    }
};
```
