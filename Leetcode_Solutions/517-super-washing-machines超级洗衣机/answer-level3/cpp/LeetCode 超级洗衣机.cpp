解题思路：
首先，先分析可以成立的情况，如果 衣服数量%机器总数 != 0，那么无法做到每一台机器都具有相同的衣服，所以我们只需要分析能做到每台机器都具有平均数量衣服的情况。
接下来先求出这个平均值，设为k。
以机器中的某一个点i为例子进行分析，设i左边有a台机器，右边有b台机器，求出k * a - sum左和k * a - sum右，如果小于0，说明这个区域多了衣服，若大于0，说明这个区域少了衣服。

![image.png](https://pic.leetcode-cn.com/b76985f4031fce94e933c3c499004a9e2f0a6c7e0c01c3bfcbb33c3c485fc82f-image.png)
```cpp
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.size() < 1) {
            return -1;
        }
        int size = machines.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += machines[i]; //生成预处理数组
        }
        if (sum % size != 0) {
            return -1;
        }
        int avg = sum / size;
        int leftSum = 0;
        int res = 0;
        for (int i = 0; i < size; i++) {
            int L = i * avg - leftSum;//i左边的需要的数目-累加和
            int R = (size - i - 1) * avg - (sum - leftSum - machines[i]);//i右边的需要数目-累加和
            if (L > 0 && R > 0) { //如果L > 0，R > 0 ，则两边都少了衣服，瓶颈在于两者之和
                res = std::max(L + R, res);
            } else { //其它情况的瓶颈都在于两者的绝对值的最大值
                res = std::max(std::max(std::abs(L), std::abs(R)), res);
            }
            leftSum += machines[i];
        }
        return res;
    }
};
```