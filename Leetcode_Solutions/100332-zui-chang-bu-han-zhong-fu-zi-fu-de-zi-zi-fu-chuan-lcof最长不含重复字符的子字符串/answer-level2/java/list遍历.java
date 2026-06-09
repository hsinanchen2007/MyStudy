### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
    ArrayList<Character> list=new ArrayList<>();
    int len=0,max=0,i=0;
    while(i<s.length()){
         if(!list.contains(s.charAt(i))){
             len++;
             list.add(s.charAt(i)); 
              if(len>max)
              max=len;
         }
         else{
             list.remove(0);
             len--;
             i--;
         }   
         i++;
    }
     return max;
    }
}
```