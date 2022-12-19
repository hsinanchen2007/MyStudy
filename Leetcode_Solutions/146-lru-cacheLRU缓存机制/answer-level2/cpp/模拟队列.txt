### 解题思路
LRU的机制比较简单：在key不重复的情况下，如果一个key最早进入cache，那么它就是最早被替换的（因为它不被访问的时间是最长的），这一点和队列的特性很相似。不同的是，在key有重复的情况下，如果对队列中已有的key进行了get或者push操作，那么它会因为被访问变成了最近访问的元素，这时候我们需要把它从队中提到队尾。
实现的大致思路如下：
1. 设置data和capacity分别充当记录缓存数据和缓存最大容量；
2. data后端当作队尾，前端当作队头，每次弹出元素在data前端，放入元素在data后端；
3. 当执行了get和put操作后，被访问的元素一定要移动到队尾；
4. put后如果data.size() > capacity，说明缓存不足，弹出队头元素。
### 代码

```cpp
class LRUCache {
private:
    vector<pair<int, int>> data;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int res = -1;
        for(int index = 0; index < this->data.size(); index++){
            if(this->data[index].first == key){
                res = this->data[index].second;
                //将刚get的元素移动到data末尾，使其为最近访问的元素
                this->data.push_back(this->data[index]);
                this->data.erase(this->data.begin() + index);
            }
        }
        return res;
    }
    
    void put(int key, int value) {
        int index = 0;
        while(index < this->data.size()){
            if(this->data[index].first == key){
                //如果key存在于data中，则更新其value，并将元素更新为最近访问的元素
                this->data[index].second = value;
                this->data.push_back(this->data[index]);
                this->data.erase(this->data.begin() + index);
                return;
            }
            index ++;
        }
        //如果key不存在于data，则创建新元素放入data，同时检查capacity是否超标
        this->data.push_back(pair<int, int>(key, value));
        if(this->data.size() > this->capacity){
            this->data.erase(this->data.begin());
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