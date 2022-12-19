这道题说人话就是：把括号所属的深度(层级)用数字标出来，然后按深度的奇偶分成0、1两组即可
比如"( ( ( ) ) ( ) )" 标记层级就是[0,1,2,2,1,1,1,0]，但是题目说只能分A(0)、B(1)两组，那么就2就按奇偶性归入0那一组即可,
运行结果[0,1,0,0,1,1,1,0]
跟官方预期答案不一样不要紧，因为这个题说了本来就有多个解，只要满足条件的都算对
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        stack<char> stk;
        for (auto& c : seq) {
            if (c == '(') {
                ans.push_back(stk.size() % 2);
                stk.push(c);
            } else {
                stk.pop();
                ans.push_back(stk.size() % 2);
            }
        }

        return ans;
    }
};
```
