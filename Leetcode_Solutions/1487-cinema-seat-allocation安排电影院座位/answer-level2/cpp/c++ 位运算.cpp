```
class Solution {
public:
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unsigned left, right, mid8, mid4;
        right = (1 << 9) - 1 ^ (1 << 5) - 1;
        left = (1 << 5) - 1 ^ 1;
        mid8 = (1 << 9) - 1 ^ 1;
        mid4 = (1 << 7) - 1 ^ (1 << 3) - 1;
        //print(mid8);
        unordered_map<int, unsigned> vis;
        int cur_n = 1, res = 0;
        unsigned temp = 0;
        for (auto& v: reservedSeats) {
            vis[v[0]] |= (1 << v[1] - 1);
        }
        for (auto& temp: vis) {
            if ((temp.second & mid8) == 0) res += 2;
            else if ((temp.second & mid4) == 0 || (temp.second & left) == 0 || (temp.second & right) == 0) res += 1;
        }
        
        return res + (n - vis.size()) * 2;
    }
};

```
