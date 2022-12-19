### 解题思路
看代码就能懂了

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        //第一种解法，题目bug就是只包含小写字符，不严谨
        /*if(s==null || s.length()==0){
            return ' ';
        }
        char c[] = s.toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        for(int i=0;i<c.length;i++){
            map.put(c[i], map.containsKey(c[i])?(map.get(c[i])+1):1);
        }
        for(int i=0;i<c.length;i++){
            if(map.get(c[i])==1){
                return c[i];
            }
        }
        return ' ';*/
        //第二种解法
        if(s==null || s.length()==0){
            return ' ';
        }
        for(char c:s.toCharArray()){
            if(s.indexOf(String.valueOf(c))==s.lastIndexOf(String.valueOf(c))){
                return c;
            }
        }
        return ' ';
    }
}
```