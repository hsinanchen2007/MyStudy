### 解题思路
思路和大家都一样啦，但是不必要用两个数组来统计，一个就够了，当a信任b时，a收集到的信任值-1就好了。
当然了应该可以在这个过程中提前退出的（直觉），但是影响不大，就不高兴想了。
### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int trustCollector[N + 1] = {0};
        int the_one_most_trusted = 1;
        int highest_trust_num = 0;

        for (int i = 0; i < trust.size(); i++)
        {
            ++trustCollector[trust[i][1]];
            --trustCollector[trust[i][0]];
        }

        for (int i = 1; i < N + 1; i++)
        {
            if (trustCollector[i] > highest_trust_num)
            {
                highest_trust_num = trustCollector[i];
                the_one_most_trusted = i;
            }
        }
        return highest_trust_num == N - 1 ? the_one_most_trusted : -1;
    }
};
```