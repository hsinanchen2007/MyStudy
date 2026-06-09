### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        char sum=t.charAt(t.length()-1);
for(int i=0;i<s.length();i++){
   sum^=s.charAt(i);
   sum^=t.charAt(i);
}
return sum;
    }
}
```