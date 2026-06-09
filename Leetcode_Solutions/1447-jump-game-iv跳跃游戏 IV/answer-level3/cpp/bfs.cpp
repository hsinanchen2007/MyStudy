直接 bfs 就行了。

但是 需要提前离散化，然后把相同的值合并一下。

bfs 可以保证 如果 “一个点是第一次到达，那么这个步数肯定最优”。然后在扩展到相同的值 和左右两边 就行了。扩展的时候当然要判断是否已经放入过了进行优化。。。。很简单。

bfs 可以用优先队列或者队列，我都试过，时间没啥差别。

可能说的不是很明白，具体看代码比较好理解。

```
struct dis {
    size_t x, step;

    dis() = default;

    dis(size_t a, size_t b) : x(a), step(b) {}

    bool operator<(const dis b) const {
        return step > b.step;
    }
};

class Solution {
public:
    static const int maxn = 5e4 + 10;
    bool vis1[maxn], vis2[maxn];
    vector<int> v[maxn];
    vector<int> Ls;

    void init() {
        for (int i = 0; i < maxn; ++i) {
            vis1[i] = vis2[i] = false;
            v[i].clear();
        }
        Ls.clear();
    }

    int minJumps(vector<int> &arr) {
        init();

        Ls = arr;
        sort(Ls.begin(), Ls.end());
        auto End = unique(Ls.begin(), Ls.end());

        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = lower_bound(Ls.begin(), End, arr[i]) - Ls.begin();
            v[arr[i]].push_back(i);
        }
        priority_queue<dis> q;
        q.push(dis(0, 0));
        while (!q.empty()) {
            dis now = q.top();  q.pop();
            if (now.x == arr.size() - 1) return now.step;
            if (now.x >= 1 && !vis1[now.x - 1]) {
                q.push(dis(now.x - 1, now.step + 1));
                vis1[now.x - 1] = true;
            }
            if (now.x + 1 < arr.size() && !vis1[now.x + 1]) {
                q.push(dis(now.x + 1, now.step + 1));
                vis1[now.x + 1] = true;
            }
            if (!vis2[arr[now.x]]) {
                vis2[arr[now.x]] = true;
                for (auto it : v[arr[now.x]]) {
                    if (!vis1[it]) {
                        q.push(dis(it, now.step + 1));
                        vis1[it] = true;
                    }
                }
            }
        }
        return 0;
    }
};
```
