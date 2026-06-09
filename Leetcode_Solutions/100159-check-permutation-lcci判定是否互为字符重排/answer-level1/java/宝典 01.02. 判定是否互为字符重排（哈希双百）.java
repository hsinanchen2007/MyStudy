### 解题思路
1.将s1放入hashmap中
2.比较s2的字符是否在map中出现，没出现返回false，出现的话将key-1，判断key是否小于0，如果小于0说明s2该字符比s1对应的多，返回false。（此处如果key-1一直大于0，就说明有其他字符的key一定小于0，因为总字符数是相同的）
3.整个循环结束将返回true，说明之前两个判断条件都符合：1.字符出现2.字符数相同。

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
         if(s1.length()!=s2.length()) return false;
         HashMap<Character,Integer> map=new HashMap<>();
         for(char c:s1.toCharArray()){
             if(map.containsKey(c)){
                 int i=map.get(c);
                 map.put(c,++i);
             }else{
                 map.put(c,1);
             }
         }
         boolean flag=false;
         for(char c:s2.toCharArray()){
             if(map.containsKey(c)){
                 int i=map.get(c);
                 map.put(c,--i);
                 if(i<0)return false;
             }else return false;
         }
         return true;
    }
}
```