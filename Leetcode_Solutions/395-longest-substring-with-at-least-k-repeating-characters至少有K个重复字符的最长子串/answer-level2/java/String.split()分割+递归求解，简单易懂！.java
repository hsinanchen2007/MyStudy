### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestSubstring(String s, int k) {
       if(s==null||s.length()==0){
           return 0; 
       }
       HashMap<Character,Integer>map=new HashMap<>();
       int len=s.length();
       for(int i=0;i<len;i++){
           char ch=s.charAt(i);
           int times=map.getOrDefault(ch,0);
           map.put(ch,++times);
       }
       String regex="";
       for(Character key:map.keySet()){
           if(map.get(key)<k){
               regex=regex+key+"|";
           }
       }
       if(regex==""){
           return s.length();
       }
       String index=regex.substring(0,regex.length()-1);
       String[] postString=s.split(index);
       int max=0;
       for(int i=0;i<postString.length;i++){
             max=Math.max(max,longestSubstring(postString[i],k));
       }
       return max;
    }
}
```