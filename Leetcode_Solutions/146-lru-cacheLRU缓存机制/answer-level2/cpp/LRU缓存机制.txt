利用链表进行操作，将最近最常使用的元素放在链表头，不常使用的放在链表尾部，具体来说就是执行操作后，将每次执行完push或者get操作的元素放在链表的开头，为此我们定义了list<pair<int,int>> queue和unordered_map<int,list<pair<int,int> >::iterator > m，其中queue中存放的是元素的key和value，而m中存放的是每个key在单链表list中的位置，实现如下：
```
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
        count=0;
    }
    
    int get(int key) {
        int res=-1;
        auto p=m.find(key);
        if(p!=m.end()){
            res=p->second->second;
            queue.erase(p->second);
            queue.push_front(make_pair(key,res));
            m[key]=queue.begin();
        }
        return res;
    }
    
    void put(int key, int value) {
        auto p=m.find(key);
        if(p!=m.end()){
            queue.erase(p->second);
        }else if(count==cap){
            int itm=queue.back().first;
            queue.pop_back();
            m.erase(itm);
        }else{
            count++;
        }
        queue.push_front(make_pair(key,value));
        m[key]=queue.begin();
    }
private:
    unordered_map<int,list<pair<int,int> >::iterator > m;
    list<pair<int,int> > queue;
    int count;
    int cap;
};
```