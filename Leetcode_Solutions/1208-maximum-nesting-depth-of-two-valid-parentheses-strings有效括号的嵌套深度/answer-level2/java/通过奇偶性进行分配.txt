### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
       int[]result=new int[seq.length()];
       int i=0;
       for(char c:seq.toCharArray()){
           result[i]=c=='('?i%2:(i+1)%2;
           i++;
       }
       return result;
    }
}
```