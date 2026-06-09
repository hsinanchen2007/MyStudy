class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int itemNum = items.size();
        map<int, multiset<int>> scoreMap;
        for (int i = 0; i < itemNum; i++) {
            int id = items[i][0];
            int score = items[i][1];
            auto it = scoreMap.find(id);
            if (it == scoreMap.end()) {  // 没找到
                multiset<int> tmpSet;
                tmpSet.insert(score);
                scoreMap.insert(pair<int, multiset<int>>(id, tmpSet));
            } else {  // 找到了
                it->second.insert(score);
            }
        }

        vector<vector<int>> resVct;
        for (auto it = scoreMap.begin(); it != scoreMap.end(); it++) {
            int id = it->first;
            int score = 0;
            int count = 0;
            for (auto it2 = it->second.rbegin(); ; it2++) {
                score += *it2;
                count++;
                if (count == 5) {
                    break;
                }
            }
            score = score / 5;
            vector<int> res;
            res.push_back(id);
            res.push_back(score);
            resVct.push_back(res);
        }

        return move(resVct);
    }
};