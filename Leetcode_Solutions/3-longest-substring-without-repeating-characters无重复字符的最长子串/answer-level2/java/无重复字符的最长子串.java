执行用时:2ms,在所有Java提交中击败了100.00%的用户
内存消耗:39MB,在所有Java提交中击败了12.98%的用户
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int []warehouse=new int[100];
        int max=0,left=-1;
        for(int i=0;i<100;i++)
            warehouse[i]=-1;
        for(int i=0;i<s.length();i++)
        {
            if(left<=warehouse[s.charAt(i)-' '])
                left=warehouse[s.charAt(i)-' ']+1;
                warehouse[s.charAt(i)-' ']=i;                
            if(max<i-left+1)
                max=i-left+1;
        }
        return max;
    }
}
```