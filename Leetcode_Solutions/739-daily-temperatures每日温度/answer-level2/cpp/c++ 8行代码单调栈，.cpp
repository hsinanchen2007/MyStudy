维持一个单调栈，栈中元素是节点温度值及对应下标，从后往前入栈；
每到一个新节点时，弹出元素直到栈顶元素大于当前值或栈为空，然后计算当前温度需要几天能超过；
栈为空则为0，当前点温度高于所有后面的点，否则结果是当前下标与栈顶下标之差。
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> results(T.size(), 0);
        stack<pair<int, int>> tStack;
        for(int i = T.size() - 1; i >= 0; i--) {
            while(!tStack.empty() && tStack.top().first <= T[i]) tStack.pop();
            results[i] = tStack.empty() ? 0 : tStack.top().second - i;
            tStack.push({T[i], i});
        }
        return results;
    }
};
```
![微信图片_20191230160344.png](https://pic.leetcode-cn.com/5978aba8d72504b4cc8bfa990151649b591bc79aaf067dd8da4f3e234fa5d674-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191230160344.png)
