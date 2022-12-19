思路： 维护一个递减的单调栈，目的是为了按照我们想要的结算顺序去结算某一位置需要几个糖果，我们需要保证从可以确定的位置一步步推算。
（假设当前遍历到的孩子编号为k）原因是当前被弹出结算的孩子（假设编号为i），他的相邻的比自己表现差的孩子肯定已经被结算了（左边的（编号为i - 1）那个被自己弹出结算了，右边（编号为i + 1）的那个被编号为k的孩子弹出结算了，一个区间没有被结算过的孩子们中极小值（波谷点）的糖果数是可以被结算的。
```
int candy(vector<int>& ratings) {
        int size = ratings.size() + 1;
        // 加入一个无穷大来弹出所有元素
        ratings.push_back(INT_MAX);
        // 初始化所有位置的糖果数为1
        vector<int> nums(size, 1);
        // 单调递减栈
        stack<int> s;
        s.push(0);
        int res = 0;
        for (int i = 1; i < size; ++i) {
            while (!s.empty()) {
                if (ratings[i] <= ratings[s.top()]) {
                    break;
                } else {
                    int index = s.top();
                    s.pop();
                    if (index < size - 1 && ratings[index] > ratings[index + 1]) {
                        nums[index] = max(nums[index], nums[index + 1] + 1);
                    }
                    if (index > 0 && ratings[index] > ratings[index - 1]) {
                        nums[index] = max(nums[index], nums[index - 1] + 1);
                    }
                    // 处于波谷的位置，可以结算，如果他比相邻的孩子表现好，可以加糖果；
                    res += nums[index];
                }
            }
            s.push(i);
        }
        return res;
    }
```
