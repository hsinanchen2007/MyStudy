将字符和字符串分别作为key，它们的位置当做value，放入<Object,Integer>类型的hashMap中。若在hashMap中没有该key，则返回null，否则，返回之前key所对应的value。若单词匹配模式，返回值应该始终相等。
```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strings = str.split(" ");
        if(pattern.length() != strings.length){
            return false;
        }
        Map<Object,Integer> hashMap = new HashMap<>();
        for(int i = 0;i < pattern.length();i++){
            if(!Objects.equals(hashMap.put(pattern.charAt(i),i),hashMap.put(strings[i],i))){
                return false;
            }
        }
        return true;
    }
}
```
