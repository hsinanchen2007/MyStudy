### 解题思路
bfs

### 代码

```cpp
class Solution {
    vector<int> dxy = {-1, 0, 1, 0, -1};
public:

    int getSum(int curx, int cury) {
        int sum = 0;
        while(curx != 0) {
            sum += curx % 10;
            curx /= 10;
        }
        while(cury != 0) {
            sum += cury % 10;
            cury /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        int res = 0;
        queue<int> que;
        vector<bool> used(m * n, false);
        que.push(0 * n + 0);
        used[0] = true;
        while (!que.empty()) {
            int curx = que.front() / n;
            int cury = que.front() % n;
            que.pop();
            int sum = getSum(curx,cury);
            if (sum <= k) {
                res++;
                for (int i = 0; i < 4; i++) {
                    int nextX = curx + dxy[i];
                    int nextY = cury + dxy[i+1];
                    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !used[nextX * n + nextY]) {
                        que.push(nextX * n + nextY);
                        used[nextX * n + nextY] = true;
                    }
                }
            }           
            
        }
        return res;
        
    }
};

```