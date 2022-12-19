关键思路：
    1、先用map保存每个点的邻接点，有重复的需要注意
    2、然后对邻接点进行排序，方便后面查找
    3、从一个点开始不断的进行深度搜索，最后n+1个点找到完成
    4、中间已经访问过的，直接在邻接点上修改。

 

    class Solution {
    public:
 
        map<string, vector<string>> mps;
        
        bool flag = false;
        
        void dfs(int size, int cnt, string cur, vector<string>& rst) {
            if (flag) return;
            
            cout << cur << "-";
            if (cnt == size - 1) {
                rst[cnt] = cur;
                flag = true;
                return;
            }
            
            rst[cnt] = cur;
            vector<string> tmp = mps[cur];
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] != "") {
                    string ss = tmp[i];
                    mps[cur][i] = "";
                    dfs(size, cnt + 1, ss, rst);
                    mps[cur][i] = ss;
                }
            }
        }
        
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            if (tickets.size() == 0) return {};
            
            for (int i = 0; i < tickets.size(); i++) {
                mps[tickets[i][0]].push_back(tickets[i][1]);
            }
            map<string, vector<string>>::iterator it;
            for (it = mps.begin(); it != mps.end(); it++) {
                sort(it->second.begin(), it->second.end());
            }
            
            vector<string> rst(tickets.size() + 1);
            
            dfs(tickets.size() + 1, 0, "JFK", rst);
            
            return rst;
        }
    };

