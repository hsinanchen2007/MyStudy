### 解题思路
首先把数组排序，问题就转变成第一个字符串和最后一个字符串公共前缀的问题了

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs==null||strs.length==0)
        {
            return "";
        }
        int size = strs.length;
        Arrays.sort(strs);
        String str1 = strs[0];
        String str2 = strs[size-1];
        StringBuffer sb = new StringBuffer();
        for(int i = 0;i < Math.min(str1.length(),str2.length());i++)
        {
            if(str1.charAt(i)==str2.charAt(i))
            {
                sb.append(str1.charAt(i));
            }
            else
            {
                break;
            }
        }
        return sb.toString();
    }
}
```