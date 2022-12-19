### 解题思路
虽然这样的解法有些慢~
### 代码

```cpp
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> help;
    MyHashSet() {
        
    }
    
    void add(int key) {
        help.push_back(key);
    }
    
    void remove(int key) {
        vector<int> temp;
        for(int i=0;i<help.size();i++)
            if(help[i]==key) temp.push_back(i);
        reverse(temp.begin(),temp.end());
        for(int t:temp) help.erase(help.begin()+t);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return find(help.begin(),help.end(),key)!=help.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```