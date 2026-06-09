## 思路
### 代码
```c++
class Logger {
    unordered_map<string, int> umap;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (umap.count(message) > 0) {
            int t = umap[message];
            if (timestamp - t < 10) {                
                return false;
            } else {
                umap[message] = timestamp;
                return true;
            }          
        }
        umap[message] = timestamp;
        return true;        
    }
};
```
#### 简化代码
```c++
class Logger {
    unordered_map<string, int> umap;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (umap.count(message) == 0 || timestamp - umap[message] >= 10) {
                umap[message] = timestamp;
                return true;           
        }        
        return false;        
    }
};
```

