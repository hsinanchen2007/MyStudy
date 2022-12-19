// 1376. Time Needed to Inform All Employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> org;
        for(int i = 0; i < n; ++i) {
            org[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(headID);
        vector<int> usedTime(n);
        int ans = 0;
        while(!q.empty()) {
            int m = q.size();
            while(m--) {
                int id = q.front();
                q.pop();
                for (int j = 0; j < org[id].size(); ++j) {
                    q.push(org[id][j]);
                    usedTime[org[id][j]] += (informTime[id] + usedTime[id]);
                    ans = max(ans, usedTime[org[id][j]]);
                }
            }
        }
        
        return ans;
    }
};