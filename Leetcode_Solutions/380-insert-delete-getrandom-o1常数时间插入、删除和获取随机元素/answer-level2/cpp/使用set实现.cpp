### 解题思路
此处撰写解题思路

### 代码

```cpp
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        /*根据插入前后的size是否发生变化来判断是否插入成功*/
        int size = temp.size();
        temp.insert(val);
        if(temp.size() == size) return false;
        else return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        /*根据删除前后的size来判断是否删除成功*/
        int size = temp.size();
        temp.erase(val);
        if(temp.size()<size) return true;
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        /*用随机数除以数组的大小，取余，余数为返回的数组中数的位置*/
        int k = rand()%temp.size();
        /*使用迭代器，来访问数组中的元素*/
        set<int>::iterator it = temp.begin();
        for(int i = 0;i<k;i++){
            it++;
        }
        return *it;
        
    }
private:
    set<int> temp;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```