### 解题思路
使用hashmap保存出现的次数

### 代码

```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        for(int i = 0;i < cpdomains.length;i++) {
            String cpdomain = cpdomains[i];
            int num = Integer.valueOf(cpdomain.substring(0, cpdomain.indexOf(" ")));
            String item = cpdomain.substring(cpdomain.indexOf(" ") + 1);
            while(item.indexOf(".") > 0) {
                map.put(item, map.getOrDefault(item, 0) + num);
                item = item.substring(item.indexOf(".") + 1);
            }
            // 这个地方可以优化一下
            if(!item.equals("")) {
                map.put(item, map.getOrDefault(item, 0) + num);
            }
        }
        List<String> result = new ArrayList<String>();
        for(String key : map.keySet()) {
            String temp = map.get(key) + " "+key;
            result.add(temp);
        }
        return result;
    }
}
```