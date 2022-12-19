```
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> m;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // 查找 key
        if (m.find(key) == m.end()) { // 查找失败，返回 ""
            return "";
        }
        map<int, string>*t_s_m = &m[key]; // 关键：要使用引用，不使用引用频繁内存拷贝会导致超时
        // 查找时间戳
        if ((*t_s_m).find(timestamp) == (*t_s_m).end()) { // 查找失败
            if (((*t_s_m).begin())->first > timestamp) { // 避免迭代器越界，timestamp 比已有的最小值还小返回 ""
                return "";
            }
            (*t_s_m)[timestamp] = ""; // 零时插入，map 会根据 timestamp 排序。
            auto it = (*t_s_m).find(timestamp); it--; // 那么 it-- ，就是比当前插入的 timestamp 小的值
            string result = (*it).second;
            (*t_s_m).erase(timestamp); // 删除零时插入值。
            return result;
        }
        else { // 查找成功
            return (*t_s_m)[timestamp];
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
```
