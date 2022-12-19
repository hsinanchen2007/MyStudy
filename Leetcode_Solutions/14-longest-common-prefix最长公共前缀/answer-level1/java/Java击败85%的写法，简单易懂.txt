### 解题思路
思路就不多说了，一个一个判断，然后主要就是应对各种特殊情况进行补充，所以显得很杂乱，不过思考流程很简单

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length<1) return "";
        if(strs.length == 1) return strs[0];
      StringBuilder StringBuilder = new StringBuilder();
      if(strs[0].length()<1) return "";
      char a = strs[0].charAt(0);
      int j=0;
      while(true){
        boolean b = false;
        for(int i=0;i<strs.length;i++){
          if(strs[i].length()<1 || strs[i].charAt(j) != a ) return StringBuilder.toString();
          if(j== strs[i].length()-1) b = true;
        }
        StringBuilder.append(String.valueOf(a));
        if(b) return StringBuilder.toString();
        j++;
        if(strs[0].length()==j) break;
        a = strs[0].charAt(j);
      }
      return StringBuilder.toString();
    }
}
```