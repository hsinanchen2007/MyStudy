map1保存key到value的映射。
map2保存 每一个不同的value 对应list结点的映射。
list是双向链表，每一个结点表示具有相同value的所有key的集合，list结点按照value从大到小排序。
```
struct Node
{
    Node(int _val):val(_val){}
    int val;
    unordered_set<string> us;
};
class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> map1;
    unordered_map<int,list<Node>::iterator> map2;
    list<Node> li;
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(map1.count(key))
        {
            int old_val=map1[key];
            auto it = map2[old_val];
            if(it==li.begin() || prev(it)->val!=old_val+1)
            {
                Node node = Node(old_val+1);
                node.us.insert(key);
                li.insert(it,node);            // 在it之前插入node
                map2[old_val+1]=prev(it);      //
            }
            else
            {
                (prev(it)->us).insert(key);
            }
            (it->us).erase(key);
            if((it->us).empty())
            {
                li.erase(it);
                map2.erase(old_val);
            }
            map1[key]++;
        }
        else
        {
            if(map2.count(1))
            {
                (map2[1]->us).insert(key);
            }
            else
            {
                Node node=Node(1);
                node.us.insert(key);
                li.push_back(node);
                map2[1]=prev(li.end());       // 别忘了.end()是非法的
            }
            map1[key]=1;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!map1.count(key)) return;
        if(map1[key]==1)
        {
            auto it=map2[1];
            (it->us).erase(key);
            if((it->us).empty())
            {
                li.erase(it);
                map2.erase(1);
            }
            map1.erase(key);
        }
        else
        {
            int old_val=map1[key];
            auto it = map2[old_val];
            if(next(it)==li.end() || next(it)->val!=old_val-1)
            {
                Node node=Node(old_val-1);
                node.us.insert(key);
                li.insert(next(it),node);          // 
                map2[old_val-1]=next(it);
            }
            else
            {
                (next(it)->us).insert(key);
            }
            (it->us).erase(key);
            if((it->us).empty())
            {
                li.erase(it);
                map2.erase(old_val);
            }
            map1[key]--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(map1.empty()) return "";
        return *(  (( li.begin() )->us).begin() );
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(map1.empty()) return "";
        return *(  (( prev(li.end()) )->us).begin() );
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
```

