### 解题思路
此处撰写解题思路

这种问题一定要想清楚可行空间。
// for (int i = start; i < s.size(); i++) {  这种是找出给定组合或子集时的可行空间。

本题中每个解都需要包含所有的元素，每次从剩余元素中选取1-3个，判断是否满足解的条件。

### 代码

```cpp
class Solution {
private:
vector<string> results;
public:
    void backTracking(string s, string res, string cur, int start, int step) {
        int temp = stoi(cur, NULL, 10);
        if (temp < 0 || temp > 255) {
            return;
        }

        if (step > 4) {
            return;
        }

        if (cur[0] == '0' && cur.size() > 1) {
            return;
        }

        res += cur + ".";
        cout << res << " | " << cur << endl;
        //cout << "xxxx" << start << " " << s.size() << endl;
        if (start == s.size() && step == 4) {
            res.pop_back();
            cout << "res" << res << endl;
            results.push_back(res);
            return;
        }
        
        //for (int i = start; i < s.size(); i++) {
            if (start < s.size()) {
                cur = s.substr(start, 1);
                cout << "cur1 " << cur << endl;
                backTracking(s, res, cur, start + 1, step + 1);
            }
            if (start + 1 < s.size()) {
                cur = s.substr(start, 2);
                cout << "cur2 " << cur << " " << start << endl;
                backTracking(s, res, cur, start + 2, step + 1);
            }
            if (start + 2 < s.size()) {
                cur = s.substr(start, 3);
                cout << "cur3 " << cur << endl;
                backTracking(s, res, cur, start + 3, step + 1);
            }
        //}
    }
    vector<string> restoreIpAddresses(string s) {
        string res;
        string cur;
        if (s.size() > 12 || s.size() < 4) {
            return results;
        }

        cur = s.substr(0, 1);
        cout << cur << endl;
        backTracking(s, res, cur, 1, 1);

        cur = s.substr(0, 2);
        backTracking(s, res, cur, 2, 1);

        cur = s.substr(0, 3);
        backTracking(s, res, cur, 3, 1);

        return results;
    }
};
```