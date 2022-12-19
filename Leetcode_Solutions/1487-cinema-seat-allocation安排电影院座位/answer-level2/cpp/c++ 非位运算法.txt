```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2 * n;
        map<int, set<int>> graph;
        for (int i = 0; i < reservedSeats.size(); i++) {
            auto t = reservedSeats[i];
            int x = t[0];
            int y = t[1];
            graph[x-1].insert(y-1);
        }

        for (auto k : graph) {
            bool left = false, right = false;
            auto v = k.second;
            // 如果1234有被预约的话那么整个ans--
            if (v.count(1) || v.count(2) || v.count(3) || v.count(4)) {
                ans--;
                left = true;
            }
            // 如果5678有被预约的话那么整个ans--
            if (v.count(5) || v.count(6) || v.count(7)  || v.count(8)) {
                ans--;
                right = true;
            }

            // 如果中间3456都没有被预约的话需要加1，因为上面两个if有可能重复减掉中间的一段
            if (!v.count(3) && !v.count(4) && !v.count(5) && !v.count(6) && left && right) ans++;
        }
        return ans;
    }
};
```