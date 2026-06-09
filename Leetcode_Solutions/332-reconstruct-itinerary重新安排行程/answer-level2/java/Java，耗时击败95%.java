### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int ticketsNum = 0;

    private Map<String, List<String>> map;

    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> trips = new ArrayList<>();
        if (tickets == null || tickets.size() == 0) {
            return trips;
        }

        ticketsNum = tickets.size();
        map = new HashMap<>();
        for (List<String> ticket : tickets) {
            String source = ticket.get(0);
            String target = ticket.get(1);
            List<String> destinations = map.getOrDefault(source, new ArrayList<>());
            destinations.add(target);
            map.put(source, destinations);
        }

        // 按字符自然排序返回最小
        for (Map.Entry<String, List<String>> item : map.entrySet()) {
            Collections.sort(item.getValue());
        }

        dfs("JFK", trips);

        return trips;
    }

    private void dfs(String start, List<String> trips) {
        if (trips.size() == ticketsNum + 1) {
            return;
        }

        List<String> destinations = map.getOrDefault(start, new ArrayList<>());
        while (destinations != null && destinations.size() > 0) {
            // 需要有序地删除
            String destination = destinations.remove(0);
            dfs(destination, trips);
        }
        // 递归到最深层开始add
        trips.add(0, start);
    }
}
```