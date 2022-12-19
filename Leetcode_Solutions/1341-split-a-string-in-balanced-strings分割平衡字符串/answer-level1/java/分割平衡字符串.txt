### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int num=0;
        int n=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='R')
                n++;
            if(s.charAt(i)=='L')
                n--;
            if(n==0)
                num++;
        }
        return num;
    }
}
```