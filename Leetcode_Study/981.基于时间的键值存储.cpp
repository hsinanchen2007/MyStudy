/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

/*

https://leetcode.cn/problems/time-based-key-value-store/

981. 基于时间的键值存储
设计一个基于时间的键值数据结构，该结构可以在不同时间戳存储对应同一个键的多个值，并针对特定时间戳检索键对应的值。

实现 TimeMap 类：

TimeMap() 初始化数据结构对象

void set(String key, String value, int timestamp) 存储键 key、值 value，以及给定的时间戳 timestamp。

String get(String key, int timestamp) 返回先前调用 set(key, value, timestamp_prev) 所存储的值，
其中 timestamp_prev <= timestamp 。如果有多个这样的值，则返回对应最大的  timestamp_prev 的那个值。
如果没有值，则返回空字符串（""）。
 
示例：

输入：
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
输出：
[null, null, "bar", "bar", null, "bar2", "bar2"]

解释：
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // 存储键 "foo" 和值 "bar" ，时间戳 timestamp = 1   
timeMap.get("foo", 1);         // 返回 "bar"
timeMap.get("foo", 3);         // 返回 "bar", 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"） 。
timeMap.set("foo", "bar2", 4); // 存储键 "foo" 和值 "bar2" ，时间戳 timestamp = 4  
timeMap.get("foo", 4);         // 返回 "bar2"
timeMap.get("foo", 5);         // 返回 "bar2"
 

提示：

1 <= key.length, value.length <= 100
key 和 value 由小写英文字母和数字组成
1 <= timestamp <= 107
set 操作中的时间戳 timestamp 都是严格递增的
最多调用 set 和 get 操作 2 * 105 次
通过次数25,366提交次数47,820

*/

// @lc code=start

class TimeMap100 {
    // 2022.7.30, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/981.%20Time%20Based%20Key-Value%20Store 
    // OJ: https://leetcode.com/problems/time-based-key-value-store/
    // Author: github.com/lzl124631x
    // Time:
    //      TimeMap: O(1)
    //      set: O(logT)
    //      get: O(logT)
    // Space: O(N)
    unordered_map<string, map<int, string, greater<>>> m;
public:
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    string get(string key, int timestamp) {
        if (m.count(key) == 0) return "";
        auto it = m[key].lower_bound(timestamp);
        return it == m[key].end() ? "" : it->second;
    }
};


class TimeMap99 {
public:
    struct T {
        string value;
        int timestamp;
        T(string value, int timestamp) : value(value), timestamp(timestamp) {}
    };

    // 2022.7.30, from https://walkccc.me/LeetCode/problems/0981/
    // Time: Constructor: O(1), set(key: str, value: str, timestamp: int): O(1), get(key: str, timestamp: int): O(logn), where n = map[key]
    // Space: O(∣set(key: str, value: str, timestamp: int)∣)
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        if (!map.count(key))
        return "";

        const auto& A = map[key];
        int l = 0;
        int r = A.size();

        while (l < r) {
        const int m = (l + r) / 2;
        if (A[m].timestamp > timestamp)
            r = m;
        else
            l = m + 1;
        }

        return l == 0 ? "" : A[l - 1].value;
    }

private:
    unordered_map<string, vector<T>> map;
};


class TimeMap98 {
public:
    // 2022.7.30, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/time-based-key-value-store.cpp
    // Time:  set: O(1)
    //        get: O(logn)
    // Space: O(n)
    void set(string key, string value, int timestamp) {
        lookup_[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!lookup_.count(key)) {
            return "";
        }
        auto it = upper_bound(lookup_[key].cbegin(),
                              lookup_[key].cend(),
                              make_pair(timestamp + 1, ""),
                              [](const pair<int, string>& lhs,
                                 const pair<int, string>& rhs) {
                                  return lhs.first < rhs.first;
                              });
        return it != lookup_[key].cbegin() ? prev(it)->second : "";
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> lookup_;
};


class TimeMap97 {
public:
    // 2022.7.30, from https://www.acwing.com/activity/content/code/content/1425822/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1425822/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    unordered_map<string, vector<pair<int, string>>> S;

    void set(string key, string value, int timestamp) {
        S[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto& q = S[key];
        pair<int, string> p(timestamp + 1, "");
        auto it = upper_bound(q.begin(), q.end(), p);
        if (it == q.begin()) return "";
        -- it;
        return it->second;
    }
};


class TimeMap {
public:
    // 2022.7.30, from https://github.com/grandyang/leetcode/issues/981
    /*
        这道题让我们实现一种基于时间的键值对儿数据结构，有两种操作 set 和 get，其中 set 就是存入键值对儿，
        同时需要保存时间戳，get 就是查找值，但此时不仅提供了 key 值，还提供了查询的时间戳，返回值的时间戳
        不能大于查询的时间戳，假如有多个相同值，返回时间戳最大的那个，若查询不到就返回空。实际上这道题考察的
        就是较为复杂一些的数据结构，因为要同时保存三个量，而且还要提供快速查询功能，可以使用 Map of Maps 
        的数据结构，外层可以使用一个 HashMap，因为对于 key 值没有顺序要求，而内层要使用一个 TreeMap，
        因为时间戳的顺序很重要。在 set 函数中直接将数据插入数据结构中，在 get 中，用一个 upper_bound 
        来进行快速查找第一个大于目标值的位置，往后退一位，就是不大于目标值的位置。但是在退之前要判断得到的位置
        是否是起始位置，是的话就没法再往前退一位了，直接返回空串，不是的话可以退一位并返回即可，参见代码如下：
    */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        dataMap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = dataMap[key].upper_bound(timestamp);
        return it == dataMap[key].begin() ? "" : prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> dataMap;
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

