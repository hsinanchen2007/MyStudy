### 解题思路
由于该计分操作最多只涉及前两轮的得分，故先想到栈的数据结构。
该题有一个坑是要考虑连续多个"+"的情况。所以计分的时候不能破坏前面几轮的得分及顺序。求完前面两轮的得分之和后，还要将前两轮的分数放回栈中。
时间复杂度：O(N)
空间复杂度：O(N)

### 代码

```cpp
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> data;
        int res = 0;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "C") {
                int score = data.top();
                res -= score;
                data.pop();
                continue;
            }

            int score = 0;
            if (ops[i] == "+") {
                int score1 = data.top();      // 倒数第一轮分数；
                data.pop();
                score = score1 + data.top();  // 加上倒数第二轮分数；
                data.push(score1);            // 将倒数第一轮分数放回，考虑连续2个"+"的情况
            } else if (ops[i] == "D") {
                score = data.top() * 2;
            } else {
                score = atoi(ops[i].c_str());
            }
            data.push(score);
            res += score;
        }
        return res;
    }
};
```