双层循环i, j 计算i与j之间的距离dis，使用map维护dis对应的数量cnt， 总数量ret += cnt * (cnt - 1)即可。
注：这种方式比较耗时，而且会出现超时的情况。
```c++ []
class Solution {
public:
    int distance(vector<int> p1, vector<int> p2) { // 计算距离
        int dis1 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        return dis1;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        int len = points.size();
        map<int, int> mp;
        map<int, int> :: iterator it;
        for (int i = 0; i < len; i++) {
            mp.clear(); // 清空map
            for (int j = 0; j < len; j++) {
                if (i == j) continue;
                int dis = distance(points[i], points[j]);
                mp[dis] ++; // 计算dis数量
            }
            for (it = mp.begin(); it != mp.end(); it ++) {
                ret += (it->second - 1) * it->second; // 计算总数量
            }
        }
        return ret;
    }
};
```
