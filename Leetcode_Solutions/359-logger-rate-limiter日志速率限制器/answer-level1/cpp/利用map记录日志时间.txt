```
class Logger {
public:
    /** Initialize your data structure here. */
    map<string, int> lastlog;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        map<string, int>::iterator iter;
        iter = lastlog.find(message);
        if(iter == lastlog.end() || timestamp - iter->second >= 10)
        {
            lastlog[message] = timestamp;
            return true;
        }
        else
        {
            return false;
        }
    }
};

```
