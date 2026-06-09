思路比较简单，根据k-1层的朋友找k层朋友，这样就可以从0层（自己）一直找到第level层；未防止重复，把已找到的朋友用set保存；
找到朋友后，再获取视频和排序就简单了
代码写的比较烂
```
class Solution {
public:
    static bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
        return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> ret;
        vector<set<int>> allLevelFriends(level + 1);
        set<int> thisLevelFriends;
        set<int> added;
        thisLevelFriends.insert(id);
        added.insert(id);
        allLevelFriends[0] = thisLevelFriends;
        for (int i = 1; i <= level; i++) {
            thisLevelFriends.clear();
            set<int> lastLevelFriends = allLevelFriends[i - 1];
            for (auto it = lastLevelFriends.begin(); it != lastLevelFriends.end(); it++) {
                vector<int> thisLevel = friends[*it];
                for(auto itor = thisLevel.begin(); itor != thisLevel.end(); itor++) {
                    if (added.count(*itor) == 0) {
                        thisLevelFriends.insert(*itor);
                        added.insert(*itor);
                    }                    
                }
            }
            allLevelFriends[i] = thisLevelFriends;
        }
        map<string, int> videoMap;
        vector<pair<string, int>> videoVec;
        for (auto it = thisLevelFriends.begin(); it != thisLevelFriends.end(); it++) {
            vector<string> video = watchedVideos[*it];
            for (auto iter = video.begin(); iter != video.end(); iter++) {
                videoMap[*iter]++;
            }
        }
        for (auto it = videoMap.begin(); it != videoMap.end(); it++) {
            videoVec.push_back(make_pair(it->first, it->second));
        }
        sort(videoVec.begin(), videoVec.end(), cmp);
        for (auto it = videoVec.begin(); it != videoVec.end(); it++) {
            ret.push_back(it->first);
        }
        return ret;
    }
};
```
