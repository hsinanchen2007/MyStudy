```
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(const auto& account: accounts)
        {
            mailNames[account[1]] = account[0];
            for(int i=1; i < account.size();i++)
            {
                if(parents.find(account[i])==parents.end())
                    parents[account[i]] = account[i];
                unit(account[i], account[1]);
            }
        }
        map<string, set<string>> parentChildren;
        for(const auto& p: parents)
            parentChildren[find(p.first)].insert(p.first);

        vector<vector<string>> mergedAccounts(parentChildren.size());
        int i=0;
        for(const auto& p: parentChildren)
        {
            mergedAccounts[i].push_back(mailNames[p.first]);
            mergedAccounts[i].insert(mergedAccounts[i].end(), p.second.begin(), p.second.end());
            i++;
        }
        return mergedAccounts;
    }
    string find(string child)
    {
        while(parents[child]!=child)
        {
            // 下面一行代码能让树的深度变浅，对于查找速度提升很大
            parents[child] = parents[parents[child]];
            child = parents[child];
        }
        return child;
    }
    void unit(string child1, string child2)
    {
        parents[find(child1)] = find(child2);
    }
private:
    unordered_map<string, string> parents;
    unordered_map<string, string> mailNames;
};
```
