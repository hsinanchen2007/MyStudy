```Java []
class Solution {
    public  int lengthOfLongestSubstringTwoDistinct(String s) {
        // 最大长度
        int max = 0;

        int n = s.length();
        int i = 0;
        int j = 0;
        Map<Character,Integer> map = new HashMap();

        while(i < n && j < n){
            if (map.containsKey(s.charAt(j))){
                max = Math.max(max,j-i+1);
                replace(s.charAt(j), j, map);
            } else if (map.size() < 2){
                map.put(s.charAt(j),j);
                max = Math.max(max,j-i+1);
            } else {
                remove(map);
                i = (Integer) map.values().toArray()[0];
                map.put(s.charAt(j),j);
            }
            j++;
        }

        return max;
    }

    private  void remove(Map<Character, Integer> map) {
        Object[] keys = map.keySet().toArray();
        if (map.get(keys[0]) > map.get(keys[1])) {
            map.remove(keys[1]);
        } else {
            map.remove(keys[0]);
        }
    }

    private  void replace(char c, int j,Map<Character, Integer> map) {
        Integer currentValue = map.get(c);
        for (Integer index : map.values()) {
            if (index > currentValue) {
                map.put(c, j);
            }
        }
    }
}
```