**方法一：**
    通过map集合获取所有元素的重复次数，返回次数只有1的元素在字符串的最小下标。
```java []
public int firstUniqChar(String s) {
         HashMap<Character, Integer> map = new HashMap<Character, Integer>();
         for (int i = 0; i < s.length(); i++) {
             char c = s.charAt(i);
             map.put(c,map.get(c)==null?1:map.get(c)+1);
         }
         Set<Character> characters = map.keySet();
         int index = -1;
         for (Character c:characters) {
             Integer integer = map.get(c);
             int i = s.indexOf(c);
             if(integer==1){
                 if(index==-1)index = i;
                 else if(index>i)index = i;
             }
         }
         return index;
     }
```

**方法二：**
      字符串封装的两个方法indexOf(c)是首次字符出现的下标。
      lastIndexOf(c)是最后一次字符出现的下标。
      两者相等说明字符唯一。
      字符有可能都不重复。需要考虑这个情况。
      
```java []
 public int firstUniqChar(String s) {
        for (int i = 0; i < s.length(); i++) {
             char c = s.charAt(i);
             if(s.indexOf(c)==s.lastIndexOf(c))return i;
         }
         return -1;
    }
```
***比较二者时间复杂度：方法一 O(n^2) 方法二 O(n)
比较二者空间复杂度：方法一 O(n)   方法二 O(1)***

