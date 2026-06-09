```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> d;
        for (int k = 0; k < arr.size(); ++k)
        {
            d[arr[k]]++;
        }
        vector<int> a;
        set<int> b;
        map<int, int>::iterator it;
        for (it = d.begin(); it != d.end(); ++it)
        {
            a.push_back(it->second);
            b.insert(it->second);
        }
        return a.size() == b.size();
    }
};
```
