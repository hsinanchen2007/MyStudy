利用优先队列表示大根堆，每次取两次top并弹出，同时插入两次top差值，直到队列大小为1

代码：
```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int num = stones.size();
        for (int i = 0; i < num; i++)
            q.push(stones[i]);
        while (q.size() > 1) {
            int big = q.top();
            q.pop();
            int small = q.top();
            q.pop();
            q.push(big - small);
        }
        return q.top();
    }
};
```
