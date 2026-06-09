### 哈希链表
用两端均可以插入，删除元素的链表作为页面的存储容器，同时使用map来存储key和页面容器的迭代器，来完成题目中的要求。
### 时间/空间
时间：O（1）
空间：O（n）
### 代码

```cpp
class LRUCache {
public:
    int cap;
    list<pair<int,int>> cache;
    map<int,list<pair<int,int>>::iterator> M;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=M.find(key);
        if(it==M.end()) return -1;              //not exist
        auto list_iter=it->second;
        pair<int,int> key_and_value=*list_iter; //get iter
        cache.erase(list_iter);                 //move to front
        cache.push_front(key_and_value);
        M[key]=cache.begin();
        return key_and_value.second;
    }
    
    void put(int key, int value) {
        auto it=M.find(key);
        if(it!=M.end()){                        //key exists
            auto list_iter=it->second;
            pair<int,int> key_and_value=*list_iter;
            key_and_value.second=value;
            cache.erase(list_iter);
            cache.push_front(key_and_value);
            M[key]=cache.begin();
        }else{                                  //key not exist
            if(cache.size()>=cap){               //cache if full
                auto list_iter=cache.back();
                int cur_key=list_iter.first;
                M.erase(cur_key);               //delete the last cache
                cache.pop_back();
                cache.push_front(make_pair(key,value));
                M[key]=cache.begin();
            } else{                             //cache is not full
                cache.push_front(make_pair(key,value));
                M[key]=cache.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```