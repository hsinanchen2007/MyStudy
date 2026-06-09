```java
class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer> map = new HashMap<>();
        
        for(char c : s.toCharArray()){
            if(map.containsKey(c)){
                map.put(c,map.get(c) + 1);
            }else {
                map.put(c,1);
            }
        }

        List<Map.Entry<Character,Integer>> list = new ArrayList<>(map.entrySet());
        //lambda表达式，按照逆序排序
        Collections.sort(list,(a,b)->(b.getValue() - a.getValue()));
        StringBuilder ans = new StringBuilder();
        for(Map.Entry<Character,Integer> entry : list){
            for(int i = 0;i < entry.getValue();i++){
                ans.append(entry.getKey());
            }
        }

        return ans.toString();
    }
}
```
