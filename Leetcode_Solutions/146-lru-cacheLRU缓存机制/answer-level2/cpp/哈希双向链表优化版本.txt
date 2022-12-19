### 解题思路
参考了高票回答，优化了部分步骤，如采用splice

### 代码

```cpp
class LRUCache {
public:
    //删除、查找、插入的复杂度都O（1）
    LRUCache(int capacity) {
        cap=capacity;
    } 
    int get(int key) {
        if(hashtable.count(key)==0) return -1;
        else//更新到表头
        {
            auto iter = hashtable[key];//找到对应结点地址
            cache.splice(cache.begin(),cache,iter);//移动到链表头
            return cache.begin()->second;//返回value
        }
    }
    
    void put(int key, int value) {
        if(hashtable.count(key)==0) {
            //如果容量到了，删除尾部元素,再加上新结点
            if(cache.size()==cap)   {
                hashtable.erase(cache.back().first);
                cache.pop_back();
            }//直接添加
            cache.push_front(make_pair(key,value));
            hashtable[key]=cache.begin(); 
        }
        else {//如果插入相同key的元素，除了要移动，value也需要更新
            auto iter = hashtable[key];
            iter->second=value;//更新地址value
            cache.splice(cache.begin(),cache,iter);//移动到链表头
            hashtable[key]=cache.begin();   //更新hashtable的value
        }
    }
    unordered_map<int,list<pair<int,int>>::iterator> hashtable;
    list<pair<int,int>> cache;//key value
    int cap=0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```