***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，持续更新。***

使用Map保存日志内容和最新一次到达系统的时间戳就行，调用打印方法时判断当前message是否存在于map，且判断上次到达系统的时间是否和此次时间间隔了10s以上。

```
class Logger {
    //使用Map保存日志内容和最新一次到达系统的时间戳
    Map<String, Integer> map;

    /**
     * Initialize your data structure here.
     */
    public Logger() {
        map = new HashMap<>();
    }

    /**
     * Returns true if the message should be printed in the given timestamp, otherwise returns false.
     * If this method returns false, the message will not be printed.
     * The timestamp is in seconds granularity.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (map.containsKey(message)) {
            //判断上次到达系统的时间是否和此次时间间隔了10s以上
            Integer lastTimestamp = map.get(message);
            if (timestamp - lastTimestamp < 10) {
                return false;
            }
        }
        map.put(message, timestamp);
        return true;
    }
}
```
