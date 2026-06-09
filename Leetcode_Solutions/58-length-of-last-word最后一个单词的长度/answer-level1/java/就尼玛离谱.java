### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
48.67%
的用户
内存消耗 :
36.3 MB
, 在所有 java 提交中击败了
52.67%
的用户

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s==null) return 0;
        int res=0;
        s=s.trim();
        if(s.equals("")||s.charAt(s.length()-1)==' '){
            return res;
        }
        String [] arry_str=s.split(" ");
        res=arry_str[arry_str.length-1].length();
        return res;
    }
}
```