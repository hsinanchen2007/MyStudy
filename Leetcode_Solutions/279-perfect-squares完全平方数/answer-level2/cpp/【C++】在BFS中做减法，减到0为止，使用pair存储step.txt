```
class Solution
{
public:
    int numSquares(int n)
    {
        int splitNum = 0;
        numQueue.push({n, 0});
        while (!numQueue.empty()) {
            pair<int, int> current = numQueue.front();
            numQueue.pop();

            int num = current.first;
            for (int i = 1; i <= sqrt(n); ++i) {
                int next = num - pow(i, 2);
                if (next < 0) {
                    break;
                }
                if (next == 0) {
                    return current.second + 1;
                }
                numQueue.push({next, current.second + 1});
            }
        }
        return splitNum;
    }

private:
    queue<pair<int, int>> numQueue;
};
```
