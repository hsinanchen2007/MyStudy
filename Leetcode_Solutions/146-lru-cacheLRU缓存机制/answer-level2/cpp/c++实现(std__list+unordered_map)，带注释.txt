```
#include <unordered_map>
#include <list>
// list 的remove操作是o(n)的，erase才是o(1)
// remove的参数是value，基于该值做遍历比较然后删除
// erase的参数是迭代器，直接删除

class LRUCache {
    // 第一个是key，第二个是value
    typedef std::list<std::pair<int,int>> LruList;
    typedef LruList::iterator list_iterator;
    typedef std::unordered_map<int, list_iterator> CacheMap;
    
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        // 如果有的话，需要把该key挪到lru链表的前方
        CacheMap::iterator it = cache_.find(key);
        if (it != cache_.end())
        {
            std::pair<int,int> origin_kv = *(it->second);
            lru_list_.erase(it->second);
            lru_list_.push_front(origin_kv);
            cache_[key] = lru_list_.begin();
            return origin_kv.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 如果存在的话，直接覆盖，然后更新lru
        CacheMap::const_iterator cit = cache_.find(key);
        if (cit != cache_.end())
        {
            lru_list_.erase(cache_[key]);
        }
        // 否则判断是否容量超过，然后更新lru，覆盖
        else if (cache_.size() >= capacity_)
        {
            std::pair<int,int> remove_key = lru_list_.back();
            cache_.erase(remove_key.first);
            lru_list_.pop_back();
        }
        lru_list_.push_front(std::make_pair(key,value));
        cache_[key] = lru_list_.begin();

    }
private:
    CacheMap cache_;
    LruList lru_list_;
    int capacity_;
};
```