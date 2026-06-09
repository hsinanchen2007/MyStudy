[广度优先搜索实现详解](http://www.iaccepted.net/algorithm/leetcode/224.html)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        init_visit(arr.size());
        return bfs(arr, start);
    }

private:
    bool bfs(vector<int> &arr, int start) {
        queue<int> que;
        int idx;
        int nw_idx;

        que.push(start);
        while (!que.empty()) {
            idx = que.front();
            que.pop();

            if (arr[idx] == 0) {
                return true;
            }

            visit[idx] = true;
            nw_idx = idx + arr[idx];
            if (nw_idx < arr.size() && !visit[nw_idx]) {
                que.push(idx + arr[idx]);
            }

            nw_idx = idx - arr[idx];
            if (nw_idx >= 0 && !visit[nw_idx]) {
                que.push(idx - arr[idx]);
            }
        }
        return false;
    }

    void init_visit(int n) {
        int i;

        for (i = 0; i < n; i++) {
            visit.push_back(false);
        }
    }

    vector<bool> visit;
};

