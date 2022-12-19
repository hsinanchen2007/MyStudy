### 解题思路
取任务前先进行排序，同类任务数多的先执行

### 代码

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int sum = 0;
        vector<int> taskCnt(26, 0);
        for (auto each : tasks) {
            taskCnt[each - 'A']++;
            sum += 1;
        }

        int result = 0;
        while (sum > 0) {
            sort(taskCnt.begin(), taskCnt.end(), greater<int>());

            int k = 0;
            for (int i = 0; i < (n + 1); ++i) {
                if (k == (n + 1) || taskCnt[k] == 0) {
                    break;
                } else {
                    taskCnt[k++] -= 1;
                    sum -= 1;
                }
            }

            result += sum == 0 ? k : (n + 1);
        }

        return result;
    }
};
```