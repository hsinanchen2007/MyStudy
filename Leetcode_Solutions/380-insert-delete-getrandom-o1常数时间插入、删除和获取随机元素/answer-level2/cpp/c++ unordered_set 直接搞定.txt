直接上代码
```
class RandomizedSet {
  unordered_set<int>s;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      if(s.count(val)) return false;
      s.insert(val);
      return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      if(!s.count(val)) return false;
      s.erase(val);
      return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
      int mod=s.size();
      srand(clock());
      int t=rand()%mod;
      return *(next(s.begin(),t));
    }
};

```
