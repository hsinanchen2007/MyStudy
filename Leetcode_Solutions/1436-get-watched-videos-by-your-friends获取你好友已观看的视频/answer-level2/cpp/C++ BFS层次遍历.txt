BFS层次遍历+限定层次，烦的点主要在于对结果的处理
```
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> myQueue;
        vector<int> visit(friends.size() ,false); //防止路径重复
        int count = 0;

        myQueue.push(id);
        visit[id] = true;
        while (level > count) {
            //这里注意要先保存起来当前层次的元素个数，不能直接!empty()，因为不断有元素在加进队列。
            int len = myQueue.size(); 
            while (len-- > 0) {
                int curId = myQueue.front();
                myQueue.pop();
                
                for (int i = 0; i < friends[curId].size(); i++) {
                    if (!visit[friends[curId][i]]) {
                        myQueue.push(friends[curId][i]);
                        visit[friends[curId][i]] = true;
                    }
                }
            }

            count++;
        }

        if (myQueue.empty()) {
            return {};
        }

        // 下面的处理都是在对结果做处理，以便符合题目要求。
        vector<string> answer;

        while (!myQueue.empty()) {
            int curId = myQueue.front();
            myQueue.pop();
            for (auto &w : watchedVideos[curId]) {
                answer.push_back(w);
            }
        }

        map<string, int> mapChar;
        for (auto &a :answer) {
            mapChar[a]++;
        }

        vector<pair<int, string>> result;
        for (auto &m : mapChar) {
            result.push_back({m.second, m.first});
        }

        sort(result.begin(), result.end(), [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });


        vector<string> finalAnswer;
        
        for (auto &r : result) {
            string temp;
            temp += r.second;
            finalAnswer.push_back(temp);
        }

        return finalAnswer;
    }
};
```
