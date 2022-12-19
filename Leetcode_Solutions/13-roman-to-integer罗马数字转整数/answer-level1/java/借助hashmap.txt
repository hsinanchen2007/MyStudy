### 解题思路

### 代码

```java
class Solution {
    public int romanToInt(String s) {
          HashMap<String,Integer> map = new HashMap();
     map.put("I",1);
     map.put("V",5);
     map.put("X",10);
     map.put("L",50);
     map.put("C",100);
     map.put("D",500);
     map.put("M",1000);
     int val = 0;
     char[] chars = s.toCharArray();
     char pre = 'a';
     boolean flog = false;
     for(int i = 0 ; i< chars.length ; i++){
         String st = String.valueOf(chars[i]);
         if((st.equals("V") || st.equals("X"))&& pre == 'I'){
             flog = true;
             val = val+map.get(st) - 1 -1;
         }
         if((st.equals("L") || st.equals("C"))&& pre == 'X'){
             flog = true;
             val = val+map.get(st) - 10 -10;
         }
         if((st.equals("D") || st.equals("M"))&& pre == 'C'){
             flog = true;
             val = val+map.get(st) - 100 - 100;
         }
         if(!flog) {
             val = val + map.get(st);
         }
         pre = chars[i];
         flog = false;
     }
     return val;
    }
}
```