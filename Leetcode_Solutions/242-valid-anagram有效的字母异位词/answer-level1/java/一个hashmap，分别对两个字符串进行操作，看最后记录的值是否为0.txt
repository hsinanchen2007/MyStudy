### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character,Integer> map = new HashMap<>();
        if(s.length() != t.length()){
            return false;
        }else{
            for(int i = 0;i < s.length();i++){
                if(map.get(s.charAt(i)) == null){
                    map.put(s.charAt(i),1);
                }else{
                    int temp = map.get(s.charAt(i)) + 1;
                    map.put(s.charAt(i),temp);
                }
            }
            for(int j = 0;j < t.length();j++){
                if(map.get(t.charAt(j)) == null){
                    return false;
                }else{
                    int temp = map.get(t.charAt(j)) - 1;
                    map.put(t.charAt(j),temp);
                }
            }
            for (Integer v : map.values()) {
                if(v != 0){
                    return false;
                }
        }
        return true;
    }
}
}
```