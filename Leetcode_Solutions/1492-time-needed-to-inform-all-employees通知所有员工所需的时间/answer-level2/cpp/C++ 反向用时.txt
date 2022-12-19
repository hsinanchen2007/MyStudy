### 解题思路
只需要寻找通知到informTime[i] == 0的所有人，所需的最大时间。
informTime[i] == 0,就代表他没有下属，是最底层的人员
![111.png](https://pic.leetcode-cn.com/eb39e5fd7ef7b9d0ee516c7b41fe297b9dd6d2a79ab537a31a2b6e1222563fae-111.png)

### 代码

```cpp
class Solution {
public:
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n <= 1)return 0;

        int max_time = 0;
        for (int i = 0; i < n; i++) {
            if (informTime[i] == 0) {//此人是底层人员
                int time = 0, lead = manager[i];
                while (lead != headID) {
                    time += informTime[lead];
                    lead = manager[lead];
                }
                time += informTime[headID];
                if (time > max_time)max_time = time;
            }
        }
        return max_time;

    }


};
```