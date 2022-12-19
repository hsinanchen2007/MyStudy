### 解题思路
此处撰写解题思路
一个数组存取所有的数，每一次删除或插入都在数组尾操作。用哈希链址法存取对应数的下标，每一次删除时先从对应值的第一个下标去除。
### 代码

```cpp
class RandomizedCollection {
public:
    vector<int>res;
    unordered_map<int,set<int>>m;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        res.push_back(val);
        m[val].insert(res.size()-1);
        return m.count(val) == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.count(val) == 0){
            return false;
        }
        int tail = res.back();
        if(tail == val){
            m[val].erase(res.size()-1);
            res.pop_back();
        }
        else{
            int index = *m[val].begin();
            m[val].erase(index);
            res[index] = tail;
            m[tail].erase(res.size()-1);
            m[tail].insert(index);
            res.pop_back();
        }
        if(m[val].empty()){
                m.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return res[rand()%(res.size())];
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