### 解题思路
从后向前遍历字符串，遍历一次。时间复杂度为o(n)
### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
         int len = s.length(),total = 0;
         if(len == 0){
             return 0;
         }
         int start = 0,end = 0;
         for(int i = len-1;i>=0;i--){
             if (s.charAt(i)!=' '){
                 start = i;
                 end = i-1;
                 break;
             }
         }
         for(int i = end;i>=0;i--){
            if(s.charAt(i)==' '){
                end = i;
                break;
            }
            end = -1; 
         }
         return start-end;
    }
}
```