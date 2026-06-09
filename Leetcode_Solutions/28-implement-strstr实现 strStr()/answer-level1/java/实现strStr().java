### 解题思路
暴力破解法，先比较字符串needle的第一个字符是否在字符串haystack中，若在接着遍历字符串needle后面的字符，同时与haystack相应的字符做比较。若不在，则跳出循环，开始比较字符串needle的第一个字符是否在字符串haystack的其它位置。

注意：循坏终止的条件，因为要使字符串haystack包含整个字符串needle，所以遍历字符串haystack的索引i后，后面所剩下的长度必须要大于等于字符串needle的长度。

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length()==0) return 0;
        if(needle.length()>haystack.length()) return -1;
        for(int i=0;i<haystack.length()-needle.length()+1;i++)
        {
            int j=0;
            for(;j<needle.length();j++)
            {
                
                if(haystack.charAt(i+j) != needle.charAt(j))
                {
                    break;
                }
   
            }

            if(j==needle.length()) return i;
            
        }
        return -1;
    }
}
```