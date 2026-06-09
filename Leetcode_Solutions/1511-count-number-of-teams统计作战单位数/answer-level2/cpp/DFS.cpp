### 解题思路
DFS搜索，挑选士兵的时候注意下标保持升序，就无需访问标记

### 代码

```cpp
class Solution {
public:
    inline bool IsVaild(vector<int>& rating, vector<int>& team)
    {
        if ((rating[team[0]] < rating[team[1]] &&
            rating[team[1]] < rating[team[2]]) ||
            (rating[team[0]] > rating[team[1]] &&
            rating[team[1]] > rating[team[2]])) {
                return true;
        }

        return false;
    }

    void DFS(vector<int>& rating, vector<int>& team, int curPos, int& ans)
    {
        if (team.size() == 3) {
            if (IsVaild(rating, team)) {
                ans++;
                return;
            } else {
                return;
            }
        }
        /*只往后找，所以不会重复*/
        for (int i = curPos + 1; i < rating.size(); ++i) {
            team.push_back(i);   
            DFS(rating, team, i, ans);
            team.pop_back();
        }
    }

    int numTeams(vector<int>& rating) {
        if (rating.size() < 3) {
            return 0;
        }

        int ans = 0;
        vector<int> team;
        for (int i = 0; i < rating.size(); ++i) {
            team.push_back(i);
            DFS(rating, team, i, ans);
            team.pop_back();
        }

        return ans;
    }
};
```