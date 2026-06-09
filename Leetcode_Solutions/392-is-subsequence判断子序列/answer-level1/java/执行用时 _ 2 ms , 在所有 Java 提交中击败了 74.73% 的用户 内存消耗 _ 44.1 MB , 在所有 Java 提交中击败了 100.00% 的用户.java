### 解题思路
1)在t中依次遍历s中的字符，
2)如果存在s中的字符不在t中的情况，return false
### 代码

```java
class Solution {
    public  boolean isSubsequence(String s, String t) {
     
      int i=0;
      int j=-1;
      while (i<s.length()){
         int flag = t.indexOf(s.charAt(i),j+1);
         if (flag == -1){
             return false;
         }
         i++;
         j= flag;
      }
      return true;
    }

   时间复杂度：O(n)
   空间复杂度：O(1)

}
```