### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
   int i=0,count=0;
   while(i<S.length()){
       if(J.indexOf(S.charAt(i))!=-1){
           count++;
       }
       i++;
   }
   return count;
    }
}
```