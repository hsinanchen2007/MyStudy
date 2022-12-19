```
class LogSystem {
    private Map<Integer, String> logMap = new HashMap<>();
    Map<String, Integer> map = new HashMap<>();

    public LogSystem() {
        map.put("Year", 4);
        map.put("Month", 7);
        map.put("Day", 10);
        map.put("Hour", 13);
        map.put("Minute", 16);
        map.put("Second", 19);
    }
    
    public void put(int id, String timestamp) {
        logMap.put(id, timestamp);
    }
    
    public List<Integer> retrieve(String s, String e, String gra) {
        String ss = s.substring(0, map.get(gra));
        String ee = e.substring(0, map.get(gra));
        List<String> list = logMap.values().stream().filter(str -> (str.substring(0, map.get(gra)).compareTo(ss) >= 0 && str.substring(0, map.get(gra)).compareTo(ee) <= 0)).collect(Collectors.toList());
        return logMap.keySet().stream().filter(index -> (list.contains(logMap.get(index)))).collect(Collectors.toList());
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(s,e,gra);
 */
```
