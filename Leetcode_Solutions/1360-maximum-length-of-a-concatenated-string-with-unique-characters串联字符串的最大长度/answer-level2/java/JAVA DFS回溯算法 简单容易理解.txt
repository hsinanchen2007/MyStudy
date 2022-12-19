```
class Solution {
    private Map<Character, Boolean> result = new HashMap<>();

    public int maxLength(List<String> arr) {
        dfs(arr, 0, new HashMap<>());
        return result.size();
    }

    public Map<Character, Boolean> dfs(List<String> arr, int index, Map<Character, Boolean> parentMap) {
        if (index >= arr.size()) {
            return parentMap;
        }
        for (int i = index; i < arr.size(); i++) {
            String str = arr.get(i);
            Map<Character, Boolean> map = new HashMap<>();
            for (Character ch : str.toCharArray()) {
                map.put(ch, true);
            }
            if (map.size() == str.length()) {
                Map<Character, Boolean> linkedMap = new HashMap<>(parentMap);
                linkedMap.putAll(map);
                if (linkedMap.size() == parentMap.size() + map.size()) {
                    Map<Character, Boolean> dfsMap = dfs(arr, i + 1, linkedMap);
                    result = dfsMap.size() > result.size() ? dfsMap : result;
                }
            }
        }
        return parentMap;
    }
}
```
