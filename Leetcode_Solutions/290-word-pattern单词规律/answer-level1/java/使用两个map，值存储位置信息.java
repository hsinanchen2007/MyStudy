```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strings = str.split(" ");
        if(strings.length!=pattern.length())return false;
        Map<Character,Integer> map1 = new HashMap<>();
        Map<String,Integer> map2 = new HashMap<>();
        for(int i=0;i<strings.length;i++){
            if (!map1.containsKey(pattern.charAt(i))) {
                map1.put(pattern.charAt(i), i);
            }
            if (!map2.containsKey(strings[i])) {
                map2.put(strings[i], i);
            }
            int a=map1.get(pattern.charAt(i));
            int b=map2.get(strings[i]);
            if(a!=b){
                return false;
            }
        }
        return true;
    }
}
```
