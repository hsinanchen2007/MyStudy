广度优先搜索，不断去搜寻最终解答，作为一种参考题解
```c++ []
class Solution {
public:
    enum class OP {COPY, PASTE};
    struct Status {
        int num;
        OP op;
        int cache;
        Status(int n, OP o, int c) : num(n), op(o), cache(c) {};
        bool operator < (const Status& other) const {
            return num < other.num || op < other.op || cache < other.cache;
        }
    };
    int minSteps(int n) {
        if (n == 1) return 0;
        queue<Status> q;
        q.push(Status(1, OP::COPY, 1));
        set<Status> seen{Status(1, OP::COPY, 1)};
        int step = 1;
        while (!q.empty()) {
            ++step;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto prev = q.front();
                q.pop();
                // copy in this step
                if (prev.op != OP::COPY) {
                    auto curr = Status(prev.num, OP::COPY, prev.num);
                    if (seen.count(curr) == 0) {
                        seen.insert(curr);
                        q.push(curr);
                    }
                }
                // paste in this step
                int num = prev.num + prev.cache;
                if (num == n) return step;
                if (num < n) {
                    auto curr = Status(num, OP::PASTE, prev.cache);
                    if (seen.count(curr) == 0) {
                        seen.insert(curr);
                        q.push(curr);
                    }
                }
            }
        }
        return step;
    }
};
```


![image.png](https://pic.leetcode-cn.com/5dba8881aedf9cb026426a93ae51434d610048a4cafcf20596c1051714707142-image.png)
