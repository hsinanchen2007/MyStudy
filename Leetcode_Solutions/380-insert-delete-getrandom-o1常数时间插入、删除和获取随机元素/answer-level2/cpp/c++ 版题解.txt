### 解题思路
c++ 版题解；用map存储位置；然后用一个vector，按照位置存放key

### 代码

```cpp
class RandomizedSet {
public:
    map<int,int> m;
    vector<int> keys;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it=m.find(val);
        if(it==m.end()){
            m[val]=keys.size();      //用map保存这个值的位置
            keys.push_back(val);     //keys保存所有的值，并且位置可以通过map找到
            return true;
        }else{
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it=m.find(val);
        if(it!=m.end()){
            int size=keys.size();
            int loc=m[val];

            m[keys[size-1]]=loc;  //把map中最后一个数对应的位置改为删除的那个数的位置
            keys[loc]=keys[size-1];  //将最后一个数的放到删除的这个数的位置
            keys.pop_back();            //删除最后一个数
            m.erase(val);           
            return true;
        }else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(keys.size() == 0) return 0;
        int index=rand()%keys.size();
        return keys[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```