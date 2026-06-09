```java
public boolean CheckPermutation(String s1, String s2) {
    if(s1.length() != s2.length()) 
        return false;
    char[] c1 = s1.toCharArray();
    char[] c2 = s2.toCharArray();
    Arrays.sort(c1);
    Arrays.sort(c2);
    return Arrays.equals(c1, c2);
}
```
--------
```java
public boolean CheckPermutation(String s1, String s2) {
    if(s1.length() != s2.length()) 
        return false;
    HashMap<Character, Integer> map = new HashMap<>();//k：字符  v：数量
    //将s1的字符添加到map中
    for(char ch : s1.toCharArray()){
        if(map.containsKey(ch)){
            int i = map.get(ch);
            map.put(ch, ++i);
        }else{
            map.put(ch, 1);
        }
    }
    //判断s2
    for(char ch : s2.toCharArray()){
        if(map.containsKey(ch)){
            int i = map.get(ch);
            map.put(ch, --i);
            if(i < 0){
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}
```
