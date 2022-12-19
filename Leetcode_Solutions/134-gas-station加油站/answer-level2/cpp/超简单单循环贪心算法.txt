算法思想：
能够走完一圈的情况：
gas[i] - cost[i] -> 在这点移动所获取的能量
由于是只能向右走，因此不管从哪个节点i出发，右边的节点都一定会经过，因此从右边开始遍历，累加所获取的能量
由于只有唯一的解，因此从起始点开始，走到右端点，所积累的能量一定是最多的，这样才可以被起始点的左边的节点所消耗
因此只要从右往左边遍历，积累的能量最多的节点就是起始点。

不能够走完一圈的情况：如果发现遍历完所积累的能量小于0，那么说明没办法走完一圈，那么返回-1
```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int max = INT_MIN;
        int maxIdx = gas.size() - 1;
        for (int i = gas.size() - 1; i >= 0; i--) {
            sum += gas[i] - cost[i];
            if (sum > max) {
                max = sum;
                maxIdx = i;
            }
        }
        if (sum < 0) {
            return -1;
        }
        return maxIdx;
    }
};
```
