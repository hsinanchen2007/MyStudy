### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int R=0,L=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='R') R++;
            else if(s.charAt(i)=='L') L++;
            if(R==L) ans++;
            if(Math.abs(R-L)>(s.length()-1-i)) return ans;
        }
        return  ans;
    }
}
```