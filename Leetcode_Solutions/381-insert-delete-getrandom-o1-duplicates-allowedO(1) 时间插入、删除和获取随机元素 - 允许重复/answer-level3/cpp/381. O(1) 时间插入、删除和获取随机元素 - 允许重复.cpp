```
class RandomizedCollection {
public:
    unordered_multiset<int> s;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val)==s.end())
        {
            s.insert(val);
            return true;
        }
        else
        {
            s.insert(val);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it=s.find(val);
        if(it==s.end())
        {
            return false;
        }
        else
        {
            s.erase(it);
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        auto it=s.begin();
        advance(it,rand()%s.size());
        return *it;
    }
};
```
