# 思路：
先将两个list的字符串和对应下标保存至两个map中，再在map中寻找相同的字符串，计算索引和，结果要始终保存索引和最小的字符串，一旦出现了索引和更小的字符串，先将结果清空，再存进去；若出现索引和等于当前最小索引和，则直接存入结果。
```
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        vector<string> res;
        for (int i = 0; i < list1.size();i++)
        {
            m1.insert({list1[i], i});
        }
        for (int i = 0; i < list2.size();i++)
        {
            m2.insert({list2[i], i});
        }
        int min = list1.size() + list2.size();//min始终保存最小的索引和
        for(auto i:m1)
        {
            if(m2.find(i.first)!=m2.end())
            {
                if(min>i.second+m2.find(i.first)->second)//出现了更小的索引和
                {
                    res.clear();//一定要清空
                    res.push_back(i.first);
                    min = i.second + m2.find(i.first)->second;
                }
                else if(min==i.second+m2.find(i.first)->second)//当前索引和等于min
                    res.push_back(i.first);
            }
        }
        return res;
    }
```
