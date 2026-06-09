单选DFS, 把每个未知状态的点作为起点探测是否可以形成环, 并增加备忘录, 用以剪枝

```
class Solution {
public:
    int len{0};
    vector<int> state;   // ID状态存储, 1:好点/0:坏点/-1:未知点, 好点是能形成环的环中的点, 坏点是不能形成环的点(通过此点的轨迹不能形成环)

    bool circularArrayLoop(vector<int> &nums)
    {
        len = nums.size();
        state.assign(len, -1);  // 初始每个点为未知状态
        for (int id = 0; id < len; id++) {
            if (state[id] == 1) {
                return true;
            }
            if (state[id] == 0) {
                continue;
            }
            bool rst = DfsDeal(id, nums);
            if (rst) {
                return true;
            }
        }
        return false;
    }

    bool DfsDeal(int curId, vector<int> &nums)
    {
        int nextId = curId + nums[curId];
        nextId = (nextId % len + len) % len;
        if (nextId == curId || nums[curId] * nums[nextId] < 0) {
            state[curId] = 0;
            return false;
        }
        if (state[nextId] == 1) {
            return true;
        }
        if (state[nextId] == 0) {
            return false;
        }
        state[curId] = 1;  // 预设curId为好点
        bool rst = DfsDeal(nextId, nums);
        if (!rst) {
            state[curId] = 0;  // 纠正curId的状态值, 为坏点
        }
        return rst;
    }
};
```
