### 解题思路
1.如果能想到用一个数组来储存每个站点上多少人，下多少人（下乘客可以用负数表示，这样就能用一个数组表示乘客上下车了）
2.然后遍历上下车的每个站点就知道当前有多少人，判断是否超过capacity。
### 代码

```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 已知：0 <= trips[i][1] < trips[i][2] <= 1000，最多有1001个站点
        // 设vector<int> cnt(1001, 0); 记录每个站点上车的人数，下车用负数表示
        // 遍历cnt就可以知道每个位置有多少乘客
        vector<int> cnt(1001, 0);
        int max_len = 0; // 记录一个最远距离，为遍历做铺垫
        
        for (int i = 0; i < trips.size(); i++) {
            cnt[trips[i][1]] += trips[i][0];
            cnt[trips[i][2]] -= trips[i][0];
            if (trips[i][2] > max_len) max_len = trips[i][2];
        }

        int currPos = 0, currPsg = 0; // currPos表示路线中的当前文职，currPsg表示每个位置的当前乘客数
        while (currPos < max_len) {
            currPsg += cnt[currPos];
            if (currPsg > capacity) return false;
            currPos++;
        }
        return true;
    }
};
```