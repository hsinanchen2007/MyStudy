虽然multimap实现就不是哈希表了，但是在这里就是要在哈希表（无序容器）的基础上排序，所以直接利用标准库会不会更好？
注：因为容许多个相等结果，所以要用multimap而不是map

```
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)    {
        //在multimap中根据键值大小排序
        multimap<int, string> buffer;
        vector<string> res;
        for (auto i = 0; i < list1.size(); ++i) {
            auto index = find(list2.begin(), list2.end(), list1[i]);
            if (index != list2.end()) {
                int sum = index - list2.begin();
                sum += i;
                buffer.insert({sum, list1[i]});
            }
        }
        //第一个肯定是最小的，先放进去
        auto beg = buffer.begin();
        int i = beg->first;
        string str = beg->second;
        res.push_back(str);
        for (beg++; beg != buffer.end(); ++beg) {
            //如果后面有跟它相等的，也放进去
            if (beg->first == i) {
                i = beg->first;
                str = beg->second;
                res.push_back(str);
            }
        }
        return res;
    }
```

