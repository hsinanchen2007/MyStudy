```
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        // key 用户组，value 为用户组 id
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < groupSizes.length; i++) {
            if (!map.containsKey(groupSizes[i])) {
                // 创建用户组
                map.put(groupSizes[i], new ArrayList<>());
            }
            // 将用户 id 放入对应的用户组
            List<Integer> sub = map.get(groupSizes[i]);
            sub.add(i);
            map.put(groupSizes[i], sub);
            // 当该用户组中的数量满了时，放入 result 集合，并清空 sub
            if (sub.size() == groupSizes[i]) {
                result.add(new ArrayList<>(sub));
                sub.clear();
            }
        }
        return result;
    }
}
```
