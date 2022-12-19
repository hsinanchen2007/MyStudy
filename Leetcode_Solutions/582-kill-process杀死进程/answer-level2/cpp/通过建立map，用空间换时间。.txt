### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        res.emplace_back(kill);
        queue<int> killQ;
        
        map<int, vector<int>> fc;
        for(int i = 0; i < ppid.size(); i++) {
            fc[ppid[i]].emplace_back(pid[i]);
        }

        killQ.push(kill);
        while (!killQ.empty()) {
            int killItem = killQ.front();
            // cout << killItem << endl;
            killQ.pop();
//关键在这里，如果不使用map，就要每次都遍历一次ppid，
            for(auto iter = fc[killItem].begin(); iter != fc[killItem].end(); ++iter) {
                killQ.push(*iter);
                res.push_back(*iter);
            }
        }
        return res;
    }
};
```