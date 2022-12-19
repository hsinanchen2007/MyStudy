### 解题思路一

STL

### 代码一

```cpp
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> dict;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        dict[key].emplace_back(timestamp, value);
    }
    
    static bool comp(const pair<int, string>& lhs, const pair<int, string>& rhs) {
        return lhs.first < rhs.first;
    }
    
    string get(string key, int timestamp) {
        auto it = std::upper_bound(dict[key].begin(), dict[key].end(), make_pair(timestamp, ""), comp);
        if(it == dict[key].begin())
            return "";
        else {
            --it;
            return it->second;
        }
    }
};

```

### 解题思路二

二分查找

### 代码二

```cpp
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> dict;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        dict[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        return binary_search(dict[key], timestamp);
    }
    
    string binary_search(vector<pair<int, string>>& vec, int v) {
        int n = vec.size();
        int lo = 0;
        int hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(vec[mid].first > v) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        // cout << lo - 1 << vec.size() << endl;
        return lo >= 1 ? vec[lo-1].second : "";
    }
};

```

或者这样写：

```cpp
string binary_search(vector<pair<int, string>>& vec, int v) {
        vector<pair<int, string>>::iterator it, first = vec.begin();
        int count, step;
        count = vec.size();
        
        while(count > 0) {
            it = first;
            step = count / 2;
            std::advance(it, step);
            if(it->first > v) {
                // hi = mid
                count = step;
            } else {
                // lo = mid + 1
                count -= (step + 1);
                first = ++it;
            }
        }
        
        return first == vec.begin() ? "" : (first - 1)->second;
    }
```
