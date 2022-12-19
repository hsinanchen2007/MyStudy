```
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        map<int, vector<int>> m;
        queue<int> q;
        q.push(kill);
        for (int i = 0; i < ppid.size(); i++) {
             map<int, vector<int>>::iterator it = m.find(ppid[i]);
            if (it != m.end()) {
                it->second.push_back(pid[i]);
                //printf("%d-%d ", pid[i], it->second.size());
            }
            else {
                vector<int> tmp;
                tmp.push_back(pid[i]);
                m.insert(make_pair(ppid[i], tmp));
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            map<int, vector<int>>::iterator it = m.find(t);
            if (it == m.end()) continue;
            vector<int> tmp = it->second;
            for (int i = 0; i < tmp.size(); i++) {
                q.push(tmp[i]);
            }
        }
        return ans;
    }
};
```
