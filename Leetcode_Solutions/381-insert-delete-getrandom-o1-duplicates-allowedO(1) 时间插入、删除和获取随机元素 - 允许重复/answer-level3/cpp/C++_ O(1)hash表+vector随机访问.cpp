**问题分析**
题目要求实现两个功能：
1. O(1)插入删除，对应可以想到使用hash表存储，即unordered_multimap
2. O(1)随机访问，对应可以想到使用数组或者vector存储

假定我们选择使用vector作为数据容器，即将所有数据存在vector中，搭配hash表存储某个值在vector中的位置，即键值对使用<数据值,数据位置>，对应功能可如下实现：
```cpp []
using hash_map = unordered_multimap<int, int>;
hash_map hm;
vector<int> vec;

bool insert(int val) {
    auto ret = hm.find(val) == hm.end();
    hm.insert(make_pair(val, int(vec.size()))); //hash表加入<值,vector长度>
    vec.emplace_back(val); //vector尾部加入新值
    return ret;
}

bool remove(int val) {
    auto find = hm.find(val); //hash表查询元素在vector中所在位置index
    if (find == hm.end()) return false;
    int idx = find->second;
    swap(vec[idx], vec.back()); //交换vector中index位置和末尾元素便于删除
    hm.erase(find); //移除查询到的元素在hash表中的存储
    vec.erase(vec.end()-1); //删除vector的末尾元素
    return true;
}
```

但是这样实现删除操作会存在一个问题，即原来存在于末尾的元素在删除结束之后会被交换到index的位置，但是hash表中的存储并没有跟着更新，仍记录着其位置为末尾。因此需要考虑hash表的更新，我们注意到实际上我们对数据的存储存在冗余，即vector中存储了数据，hash表的键中也存储了所有的数据，于是不妨换个思路，使hash表指向vector的同时，也将vector指向hash表，即将vector中存储的内容更改为对应元素在hash表中的迭代器，这样我们就可以找到交换对象（即末尾元素）在hash表中的迭代器并更新啦！

**完整代码：**
```cpp []
class RandomizedCollection {
public:
    using hash_map = unordered_multimap<int, int>;
    hash_map hm;
    vector<hash_map::iterator> vec;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto ret = hm.find(val) == hm.end();
        auto it = hm.insert(make_pair(val, int(vec.size())));
        vec.emplace_back(it);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto find = hm.find(val);
        if (find == hm.end()) return false;
        int idx = find->second;
        vec.back()->second = idx; //update hash table
        swap(vec[idx], vec.back());
        hm.erase(find);
        vec.erase(vec.end()-1);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand()%vec.size()]->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
