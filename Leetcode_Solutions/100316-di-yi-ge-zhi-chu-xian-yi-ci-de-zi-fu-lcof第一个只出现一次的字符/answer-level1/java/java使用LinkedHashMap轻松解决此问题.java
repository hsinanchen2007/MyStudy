看到问题最开始的想法是使用一个Map记录每个字符出现的次数，然后遍历Map的值，当遇到第一个1时，return这个1对应的key。
但是写完测试不用同，才发新HashMap中数据的插入是无序的，也就是说key的记录顺序并不是同写入时的顺序一样。而HashMap的子类**LinkedHashMap可以保持KEY值顺序与放入顺序一致**，所以完美解决此问题~~~


```
class Solution {
    public char firstUniqChar(String s) {
        Map<Character, Integer> map = new LinkedHashMap<>();
        for(int i=0; i<s.length(); i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i),0)+1);
        }
        for(char sss : map.keySet()){
            if(map.get(sss) == 1) return sss;
        }
        return ' ';
    }
}
```
