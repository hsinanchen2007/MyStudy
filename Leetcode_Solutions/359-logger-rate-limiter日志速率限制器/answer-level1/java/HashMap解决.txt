### 解题思路
使用hashmap进行处理，代码如下

### 代码

```java
class Logger {

    Map<String, Integer> log;
    /** Initialize your data structure here. */
    public Logger() {
        log = new HashMap<>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if(log.containsKey(message)){
            int time = log.get(message);
            if((timestamp - time) >= 10) {
                log.put(message, timestamp);
                return true;
            }
            else return false;
        }else{
            log.put(message, timestamp);
            return true;
        } 
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
```