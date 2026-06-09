### 解题思路
BFS的题目总是要写好长好长一大段，而且涉及小细节极多。

### 代码

```cpp
class Solution {
public:
    static bool myfun(pair<string, int> a, pair<string, int> b)
    {
        if (a.second < b.second) {
            return true;
        } else if (a.second == b.second) {
            if (a.first < b.first) {
                return true;
            }
        }

        return false;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id,
        int level)
    {
        unordered_map<int, vector<int>> friendmap;
        unordered_map<string, int> vediocount;
        vector<pair<string, int>> strpair;
        vector<string> result;
        vector<int> visit = vector<int>(friends.size(), 0);
        deque<int> buff;
        int count = 0;

        for (int i = 0; i < friends.size(); i++) {
            for (auto f : friends[i]) {
                friendmap[i].push_back(f);
            }
        }

        buff.push_back(id);
        visit[id] = 1;

        while (!buff.empty()) {
            count++;
            int length = buff.size();

            for (int i = 0; i < length; i++) {
                int currentid = buff.front();
                for (auto friendid : friendmap[currentid]) {
                    if (visit[friendid] != 1) {
                        visit[friendid] = 1;
                        buff.push_back(friendid);

                        if (count == level) {
                            for (auto s : watchedVideos[friendid]) {
                                vediocount[s]++;
                            }
                        }
                    }
                }
                buff.pop_front();
            }

            if (count == level) {
                break;
            }
        }

        for (auto vedio : vediocount) {
            strpair.push_back(vedio);
        }

        sort(strpair.begin(), strpair.end(), myfun);

        for (auto str : strpair) {
            result.push_back(str.first);
        }

        return result;
    }
};
```