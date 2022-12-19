1.分group和item两层处理；
2.group为-1单独分配一个组号;;
```
class Solution {
private:
    // index by group id
    vector<vector<int>> Groups;
    vector<unordered_set<int>> GroupsBefore;

    // index by item id
    vector<int> *ItemGroup;
    vector<vector<int>> *ItemBefore; 
    
    unordered_set<int> handledGroup;
    unordered_set<int> handledItem;
    vector<int> res;

    int _handleOneItem(const int &item, unordered_set<int> &st) {
        int rc = 0;
        if (st.count(item))
            return -1;

        if (handledItem.count(item))
            return 0;
        
        //处理依赖
        st.insert(item);
        for (auto &i:(*ItemBefore)[item]) {
            if ((*ItemGroup)[i] == (*ItemGroup)[item]) {
                rc = _handleOneItem(i, st);
                if (rc < 0) return rc;
            }
        }
        st.erase(item);
        
        // 处理自己
        res.emplace_back(item);
        handledItem.insert(item);
        return rc;
    }

    int _arrangeOneGroup(const int &gid) {
        unordered_set<int> st;
        int rc = 0;
        
        for (auto &iid:Groups[gid]) {
            rc = _handleOneItem(iid, st);
            if (rc < 0) return rc;
        }   
        
        return rc;
    }

    int _handleOneGroup(const int &gid, unordered_set<int> &st) {
        int rc = 0;
        if (st.count(gid)) {
            return -1;
        }

        if (handledGroup.count(gid))
            return 0;

        //处理依赖
        st.insert(gid);
        for (auto &j : GroupsBefore[gid]) {
            rc = _handleOneGroup(j, st);
            if (rc < 0) return rc;
        }
        st.erase(gid);

        handledGroup.insert(gid);
        // 处理自己
        return _arrangeOneGroup(gid);
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {       
        int rc;

        ItemGroup = &group;
        ItemBefore = &beforeItems;
        
        // items分组，每个-1专门一组
        Groups.resize(m);
        int start = m;
        for (int i = 0; i < n; ++i) {
            if ((*ItemGroup)[i] == -1) {
                vector<int> t = {i};
                Groups.emplace_back(t);
                (*ItemGroup)[i] = start++;
            } else {
                Groups[(*ItemGroup)[i]].emplace_back(i);
            }
        }

        // 找到有依赖的组
        GroupsBefore.resize(Groups.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (*ItemBefore)[i].size(); ++j) {
                int groupID = (*ItemGroup)[(*ItemBefore)[i][j]];
                if (groupID != (*ItemGroup)[i])
                    GroupsBefore[(*ItemGroup)[i]].insert(groupID);
            }
        }

        // 一组组打印
        unordered_set<int> tmp;
        for (int i = 0; i < Groups.size(); ++i) {
            rc = _handleOneGroup(i, tmp);
            if (rc < 0) {
                res.clear();
                return res;
            }
        }
        return res;
    }
};
```
