

### 代码

```cpp
class MapSum {
public:
    /** Initialize your data structure here. */
    map<string,int> help;

    MapSum() {

    }
    
    void insert(string key, int val) {
        help[key]=val;
    }
    
    int sum(string prefix) {
        int ans=0;
        
        for(auto h:help)
            if(h.first.find(prefix)==0) 
                ans+=h.second;
        
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```