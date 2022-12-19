- 利用map，key为组长度，value为组中成员id，
- 遍历groupSizes，为每个不同组长度建立kv，
- 当value长度等于k，删除value，并添加进返回结果resList
- 最后把剩余value添加进resList

```
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<List<Integer>> resList = new ArrayList<>();
        for (int i = 0; i < groupSizes.length; i++) {
            if (!map.containsKey(groupSizes[i])) {
                map.put(groupSizes[i], new ArrayList<>());
            } else if (map.get(groupSizes[i]).size() == groupSizes[i]) {
                resList.add(map.remove(groupSizes[i]));
                map.put(groupSizes[i], new ArrayList<>());
            }
            map.get(groupSizes[i]).add(i);
            }
        for (Integer integer : map.keySet()) { //把剩余的组添加进结果中
            resList.add(map.get(integer));
        }
        return resList;
    }
```
