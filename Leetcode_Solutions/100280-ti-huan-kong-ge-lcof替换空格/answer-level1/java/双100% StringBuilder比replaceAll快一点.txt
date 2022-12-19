### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
      public String replaceSpace(String s) {
          StringBuilder st=new StringBuilder();
         char[] ss= s.toCharArray();
          for (char c : ss) {
             {
              if(c==' ') {
                  st.append("%20");
          }
               
              else {
                  st.append(c);
              }
          }
          }
          return st.toString();

      }
}
```