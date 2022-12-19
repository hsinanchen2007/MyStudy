### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> letterCasePermutation(String S) {
        List<StringBuilder> ans=new ArrayList<>();
        ans.add(new StringBuilder());

        for(char c:S.toCharArray())
        {
            int n=ans.size();
            if(Character.isLetter(c))
            {
                for(int i=0;i<n;i++)
                {
                    ans.add(new StringBuilder(ans.get(i)));
                    ans.get(i).append(Character.toLowerCase(c));
                    ans.get(n+i).append(Character.toUpperCase(c));
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                    ans.get(i).append(c);
            }
        }

        List<String> res=new ArrayList<>();
        for(StringBuilder sb:ans)
            res.add(sb.toString());
        return res;
    }
}
```