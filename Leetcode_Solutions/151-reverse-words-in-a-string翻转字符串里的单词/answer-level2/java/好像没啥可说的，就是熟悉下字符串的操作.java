RT

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] help = s.trim().split(" ");
        int n = help.length;
        StringBuilder sb = new StringBuilder();
        for(int i = n-1;i >= 0;i--)
        {
            if(help[i].equals(""))
            {
                continue;
            }
            else
            {
                sb.append(help[i]);
                sb.append(" ");
            }
        }
        return sb.toString().trim();
    }
}
```