>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 哈希表

执行用时：41ms，击败42.11%。消耗内存：52.6MB，击败100.00%。

```java
public class Logger {
    private Map<String, Integer> map;

    public Logger() {
        map = new HashMap<>();
    }

    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!map.containsKey(message) || map.get(message) + 10 <= timestamp) {
            map.put(message, timestamp);
            return true;
        }
        return false;
    }
}
```