使用队列实现 BFS 思路，比较简单

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> spid;
        for(int i= 0; i< ppid.size();i++){
            spid[ppid[i]].push_back(pid[i]);
        }
        queue<int> Q;
        vector<int> res;
        for(auto s : spid[kill]){
            Q.push(s);
        }
        res.push_back(kill);
        while(!Q.empty()) {
            res.push_back(Q.front());
            for(auto p:spid[Q.front()])
            {Q.push(p);}
            Q.pop();
        }
        return res;
    }
};