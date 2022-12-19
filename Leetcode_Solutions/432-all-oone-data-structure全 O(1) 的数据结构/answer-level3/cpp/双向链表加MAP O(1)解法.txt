```
class AllOne {
public:
    list<pair<int, set<string>>> DoubleList;
    unordered_map<string, list<pair<int, set<string>>>::iterator> hashMap;
    /** Initialize your data structure here. */
    AllOne() {
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto iter = hashMap.find(key);
        if (iter != hashMap.end())
        {
            int count = iter->second->first + 1;
            iter->second->second.erase(key);
            auto ListIter = iter->second;
            iter->second++;
            if (iter->second != DoubleList.end() && iter->second->first == count)
            {
                iter->second->second.insert(key);
                hashMap[key] = iter->second;
            }
            else
            {
                set<string> setStr;
                setStr.insert(key);
                hashMap[key] = DoubleList.insert(iter->second, make_pair(count, setStr));
            }
            if (ListIter->second.size() == 0)
                DoubleList.erase(ListIter);
        }
        else
        {
            auto iter = DoubleList.begin();
            if (iter != DoubleList.end() && iter->first == 1)
            {
                iter->second.insert(key);   
                hashMap[key] = DoubleList.begin();
            }
            else
            {
                set<string> setStr;
                setStr.insert(key);
                DoubleList.push_front(make_pair(1, setStr));
                hashMap[key] = DoubleList.begin();
            }
        }
    }
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto iter = hashMap.find(key);
        if (iter != hashMap.end())
        {
            auto ListIter = iter->second;
            int count = iter->second->first - 1;
            if (iter->second == DoubleList.begin())
            {
                if (iter->second->first == 1)
                {
                    iter->second->second.erase(key);
                    hashMap.erase(key);
                }
                else
                {
                    set<string> setStr;
                    setStr.insert(key);
                    DoubleList.push_front(make_pair(count, setStr));
                    hashMap[key] = DoubleList.begin();
                }
            }
            else
            {
                iter->second->second.erase(key);
                iter->second--;
                if (iter->second->first == count)
                {
                    iter->second->second.insert(key);
                    hashMap[key] = iter->second;
                }
                else
                {
                    set<string> setStr;
                    setStr.insert(key);
                    hashMap[key] = DoubleList.insert(ListIter, make_pair(count, setStr));
                } 
            }
            if (ListIter->second.size() == 0)
                DoubleList.erase(ListIter);
        }
    }
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (DoubleList.size() > 0)
            return *(DoubleList.back().second.begin());
        return "";
    }
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (DoubleList.size() > 0)
            return *(DoubleList.begin()->second.begin());
        return "";
    }
};
```
