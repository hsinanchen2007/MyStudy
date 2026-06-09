### 解题思路
设s为源字符串去除掉前后的空格。那么：
从后往前遍历：
如果s[i]!=' '&&s[i-1]==' '，说明s.substring(i,end)必须加入答案字符串
end的定义：如果s[i]==' '&&s[i-1]!=' '，说明end必须开始记为i，指新单词的开始。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String source=s.trim();
        StringBuilder ans=new StringBuilder();
        StringBuilder sb=new StringBuilder(source);
        int end=source.length();

        for(int i=end-1;i>=1;i--)
        {
            if(sb.charAt(i)!=' '&&sb.charAt(i-1)==' ')
            {
                ans.append(sb.substring(i,end));
                ans.append(" ");
            }
            if(sb.charAt(i)==' '&&sb.charAt(i-1)!=' ')
                end=i;
        }

        ans.append(sb.substring(0,end));

        return ans.toString();
    }
}
```