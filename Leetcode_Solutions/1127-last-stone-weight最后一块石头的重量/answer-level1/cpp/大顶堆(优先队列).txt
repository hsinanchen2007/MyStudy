### 解题思路
大顶堆(优先队列)，就按照题目的步骤来就行了

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto& s : stones) {
            q.push(s);//建立大顶堆
        }

        while (q.size() > 1) {
            int firstStone = q.top();
            q.pop();
            int secondStone = q.top();
            q.pop();
            if (firstStone != secondStone) {
                int newStone = firstStone - secondStone;
                q.push(newStone);
            }
        }

        if (q.empty()) {
            return 0;
        } else {
            return q.top();
        }
    }
};
```