### 解题思路
Java使用哈希表统计字数

### 代码

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character,Integer> map = new HashMap<>();
        for(char mag : magazine.toCharArray()){
            map.put(mag, map.getOrDefault(mag, 0) + 1);
        }
        for(char ran : ransomNote.toCharArray()){
            if(map.get(ran) == null){
                return false;
            }else if(map.get(ran) > 0){
                map.put(ran, map.get(ran) - 1);
            }else{
                return false;
            }
        }
        return true;
    }
}
```