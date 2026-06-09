```
class Solution {
public:
    void UpdateFreq(vector<vector<string>>& watchedVideos, int id) {
        vector<string> &videos = watchedVideos[id];
        for (auto v : videos) {
            freq[v]++;
        }
        return;
    }

    struct Node {
        string vedio;
        int times;
        Node(string v, int t) : vedio(v), times(t) 
        {
        }
        bool operator < (const Node &n) const
        {
            if (times < n.times) {
                return true;
            } else if (times == n.times) {
                return vedio < n.vedio;
            }
            return false;
        }
    };

    vector<string> GetRes()
    {
        set<Node> ms;
        vector<string> res;
        for (auto m : freq) {
            ms.insert(Node(m.first, m.second));
        }
        for (auto m : ms) {
            res.push_back(m.vedio);
        }
        return res;
    }

    void Bfs(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level)
    {
        int n = friends.size();
        vector<bool> fidflag(n, 0);

        queue<int> mq;
        mq.push(id);
        fidflag[id] = true;

        int step = 0;
        while(!mq.empty()) {
            step++;
            int len = mq.size();
            for (int i = 0; i < len; i++) {
                int fid = mq.front();
                mq.pop();
                for(auto f : friends[fid]) {
                    if (fidflag[f]) {
                        continue;
                    }
                    mq.push(f);
                    fidflag[f] = true;
                    if (step == level) {
                        UpdateFreq(watchedVideos, f);
                    }
                }
            }

            if (step == level) {
                break;
            }
        }
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        Bfs(watchedVideos, friends, id, level);
        return GetRes();
    }
private:
    map<string, int> freq;    
};
```
