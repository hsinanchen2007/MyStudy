### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int n1 = g.length;
        int n2 = s.length;
        int result = 0;

        Arrays.sort(g);
        Arrays.sort(s);
        int j=0;

        for(int i=0;i<n2;i++)
        {
            while(j<n1)
            {
                if(s[i]>=g[j])
                {
                    result++;
                    j++;
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        return result;
    }
}
```