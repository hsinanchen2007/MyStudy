### 解题思路
日志文件的id和时间戳均唯一，retrieve方法又是按照时间维度获取日志id的。所以，可以以时间戳为key，id为value存储在天生有序的TreeMap中，利用红黑树的有序性，输出日志id。

时间区间的获取需要特殊处理一下，截取时间级别后，需要在截取的后面，补齐被截取掉的部分。开始时间默认是01月01日0时0分0秒。结束时间默认12月31日23时59分59秒。对于一个月到底是多少天，这个不用处理，都默认为31即可，反正不会有日大于31的情况出现。

最后就是对红黑树进行区间查询。输出日志id。

### 代码

```java
class LogSystem {
    
    // key->时间 value->日志id
    private TreeMap<String,Integer> m_logMap;
    // key->gra value->0截取长度，1开始时间的后序，2结束时间的后序
    private Map<String,String[]> m_graMap = new HashMap<>();

    public LogSystem() {
        m_logMap = new TreeMap<>();
        m_graMap.put("Year",new String[]{"4",":01:01:00:00:00",":12:31:23:59:59"});
        m_graMap.put("Month",new String[]{"7",":01:00:00:00",":31:23:59:59"});
        m_graMap.put("Day",new String[]{"10",":00:00:00",":23:59:59"});
        m_graMap.put("Hour",new String[]{"13",":00:00",":59:59"});
        m_graMap.put("Minute",new String[]{"16",":00",":59"});
        m_graMap.put("Second",new String[]{"19","",""});
    }

    public void put(int id, String timestamp) {
        m_logMap.put(timestamp,id);
    }

    public List<Integer> retrieve(String s, String e, String gra) {
        String[] graAttr = m_graMap.get(gra);
        int limit = Integer.valueOf(graAttr[0]);
        // 时间重新填充
        s = s.substring(0,limit) + graAttr[1];
        e = e.substring(0,limit) + graAttr[2];
        // 把treeMap里的id全部输出
        return new ArrayList<>(m_logMap.subMap(s,true,e,true).values());
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(s,e,gra);
 */
```