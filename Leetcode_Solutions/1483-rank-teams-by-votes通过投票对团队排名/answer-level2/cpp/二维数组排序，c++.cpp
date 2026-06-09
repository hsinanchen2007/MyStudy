思路：
1）创建27*27数组，保存每个队伍的名次。行表示队伍，列表示名次。在每行的最后1个冗余位保存队伍名称
2）用sort函数对二维数组排序，进行降序排序，要用gerater
3）输出排序后二维数组的每一行的最后一位，string累加即为结果

```
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> dw(27, vector<int>(27, 0)); // 初始化27*27数组，保存每个队伍的名次，行为队伍，列为名次。同时在每行的最后1位保存队伍名称
        string str;
        for (auto v : votes) {
            for (int j = 0; j < v.length(); j++) {
                dw[v[j] - 'A'][j]++; //横坐标为队伍，纵坐标为名次。v[j]为队伍，j为名次
                dw[v[j] - 'A'].back() = 26 - (v[j] - 'A');
            }
        }
        sort(dw.begin(), dw.end(), greater<vector<int>>());
        for (auto d : dw) {
            if (d.back() != 0) {
                str += (26 - d.back() + 'A');
            }
        }
        return str;
    }
};
```
