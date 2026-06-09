### 解题思路
嵌套循环就完事了，O(n^2)

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
         String item=new String();
         boolean flag=true;
         for(int i=0;i<astr.length();i++){
             int j=i+1;
             char c=astr.charAt(i);
             while(j<astr.length()){
                 if(c==astr.charAt(j))return false;
                 ++j;
             }
         }
         return flag;
    }
}
```