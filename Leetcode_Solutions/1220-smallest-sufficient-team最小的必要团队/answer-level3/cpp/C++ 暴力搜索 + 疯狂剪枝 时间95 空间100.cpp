两步预处理
1. 去掉所有不在需求列表里面的员工技能
2. 去掉所有能被另外一个员工完全替代的员工 包括技能为空的员工

```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> strMap;
        int count = 0;
        for (string& str : req_skills)
            if (!strMap.count(str))
                strMap[str] = count++;

        // pre-processing
        vector<pair<int, int>> people2;
        for (int i = 0; i < people.size(); ++i) {
            pair<int, int> p = { i, 0 };
            for (int j = 0; j < people[i].size(); ++j) {
                if (strMap.count(people[i][j]))
		    p.second |= 1 << strMap[people[i][j]];
	    }
	    if (p.second)
		people2.push_back(p);
	}

        // pre-processing
        vector<pair<int, int>> people3;
        for (int i = 0; i < people2.size(); ++i) {
            bool flag = true;
            for (int j = i + 1; j < people2.size(); ++j)
                flag &= (people2[i].second & people2[j].second) != people2[i].second;
            if (flag)
                people3.push_back(people2[i]);
        }
        people2 = move(people3);

        int target = (1 << strMap.size()) - 1;
	vector<int> result;
	vector<int> curVec;
	vector<int> visited(1 << strMap.size(), INT_MAX);
	vector<pair<int, int>>::iterator iter = people2.begin();
	for (int i = 0; i < people.size(); ++i)
	    result.push_back(i);

	dfsSST(visited, result, curVec, target, people2, 0, iter);

	return result;
    }

    void dfsSST(vector<int>& visited, vector<int>& result, vector<int>& curVec, int& target, vector<pair<int, int>>& people, int cur, vector<pair<int, int>>::iterator& iter) {
        if (visited[cur] != INT_MAX && curVec.size() > visited[cur])
            return;
        visited[cur] = min(visited[cur], (int)curVec.size());
        if (cur == target && curVec.size() < result.size()) {
            result = curVec;
	    return;
        }
        if (cur == target || iter == people.end() || curVec.size() >= result.size())
            return;
        curVec.push_back(iter->first);
        int i = iter->second;
        ++iter;
        dfsSST(visited, result, curVec, target, people, cur | i, iter);
        curVec.pop_back();
        dfsSST(visited, result, curVec, target, people, cur, iter);
        --iter;
    }
};
```