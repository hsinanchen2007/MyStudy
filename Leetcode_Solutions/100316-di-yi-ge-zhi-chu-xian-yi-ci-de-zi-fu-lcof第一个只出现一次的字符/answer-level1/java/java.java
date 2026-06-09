```java
class Solution {
      public char firstUniqChar(String s) {
        int[] count=new int[128];
        char res=32;
        int index=s.length();
        for (int i = 0; i <s.length() ; i++) {
            char c = s.charAt(i);
            count[c]++;
        }
        for (int i = 0; i <count.length ; i++) {
            if (count[i]==1){
                int in = s.indexOf((char) i);
                index=Math.min(index,in);
                res=s.charAt(index);
            }
        }
        return res;
    }
}
```