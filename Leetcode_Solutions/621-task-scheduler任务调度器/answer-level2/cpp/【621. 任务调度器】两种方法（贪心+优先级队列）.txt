## 思路一：贪心
### 代码
```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        int count = 0, same = 0, res = 0;
        for (char c : tasks) {
            ++umap[c];
            count = max(count, umap[c]);
        }
        for (auto m : umap) {
            if (m.second == count) {
                ++same;
            }
        }
        res = (count - 1) * (n + 1) + same;
        return max((int)tasks.size(), res);
    }
};
```

## 思路二：优先级队列
优先级队列按照元素出现次数进行排序。
while(队列不为空)
- 每次从队列中取出 n + 1 个元素
- 将每个元素次数减一，如果不为 0，则再次放入队列
- 如果队列不为空，则说明前一次完整取出 n + 1 个元素，将结果加到 res，否则取实际取出元素个数 cnt 加到 res。
### 代码
```
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        priority_queue<int> pq;
        int res = 0;
        for (char c : tasks) {
            ++umap[c];
        }
        for (auto m : umap) {
            pq.push(m.second);
        }
        while (!pq.empty()) {
            int cnt = 0;
            vector<int> task;
            for (int i = 0; i < n + 1; ++i) {
                if (!pq.empty()) {
                    task.push_back(pq.top());
                    pq.pop();
                    ++cnt;
                }
            }
            for (int d : task) {
                if (--d > 0) {
                    pq.push(d);
                }
            }
            res += pq.empty() ? cnt : n + 1;
        }
        return res;
    }
};
```

