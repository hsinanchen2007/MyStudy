### 解题思路
双指针的思路，一个指针扫描字符串s，一个指针扫描字符串t。每次比较后将t的指针往后移一位；比较成功后将s的指针往后移一位。当字符串s扫描完，说明s是t的子串。
时间复杂度：O(n)。n是字符串t的长度。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length()==0)   
            return true;
        int i=0,j=0;
        while(j<t.length())
        {
            if(s.charAt(i)==t.charAt(j))    i++;
            j++;
            if(i==s.length())   
                return true;
        }
        return false;
    }
}
```