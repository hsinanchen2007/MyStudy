```
class Solution {
public:
    using Content = string;
    using Paths = vector<string>;
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        unordered_map<Content, Paths> dupMap;
        for (const auto &path : paths) {
            istringstream iss(path);
            string curPath;
            iss >> curPath;
            string nameCon;
            while (iss >> nameCon) {
                auto posNameEnd = nameCon.find('(');
                string fileName = nameCon.substr(0, posNameEnd);
                string content = nameCon.substr(posNameEnd + 1, nameCon.size() - 1 - (posNameEnd + 1));
                dupMap[content].push_back(curPath + "/" + fileName);
            }
        }
        vector<vector<string>> ans;
        for (const auto &ele : dupMap) {
            if (ele.second.size() > 1) {
                ans.push_back(ele.second);
            }
        }
        return ans;
    }
};
```
