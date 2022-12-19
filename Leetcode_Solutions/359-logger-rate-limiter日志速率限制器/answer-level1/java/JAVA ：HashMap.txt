### 解题思路
此处撰写解题思路

### 代码

```java
class Logger {
    HashMap<String, Integer> logMessage;
    /** Initialize your data structure here. */
    public Logger() {
        logMessage = new HashMap<String, Integer>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if(logMessage.containsKey(message)) {
            int lastTime = logMessage.get(message);
            if(timestamp - lastTime >= 10) {
                logMessage.put(message, timestamp);
                return true;
            } else {
                return false;
            }
        }
        logMessage.put(message, timestamp);
        return true;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
```