### 解题思路
拓扑排序模板题，就没啥好说的。
题中说明输入只可能是小写字符，因此用一个int型变量就可存储相邻的节点了。
只是调试起来看中间变量相对比较麻烦，都是二进制还要换算才能对号入座，还好一次过了。

### 代码

```java
class Solution {
    public String alienOrder(String[] words) {
        if(words==null||words.length==0)
        {
            return "";
        }
        StringBuilder ans = new StringBuilder(26);
        int[] mapIn = new int[26];
        int[] mapOut = new int[26];
        boolean[] has = new boolean[26];
        int aLen = 0;
        for (int j = 0; j < words[0].length(); j++) {
            int lj = words[0].charAt(j)-'a';
            aLen=!has[lj]?aLen+1:aLen;
            has[lj]=true;
        }
        for (int i = 1; i < words.length; i++) {
            String last = words[i-1];
            String cur = words[i];
            int len = Math.min(last.length(),cur.length());
            for (int j = 0; j < cur.length(); j++) {
                int lj = cur.charAt(j)-'a';
                aLen=!has[lj]?aLen+1:aLen;
                has[lj]=true;
            }
            for (int j = 0; j < len; j++) {
                if(last.charAt(j)!=cur.charAt(j))
                {
                    int labc = cur.charAt(j)-'a';
                    int labl = last.charAt(j)-'a';
                    mapOut[labc] |= 1<<(labl);
                    mapIn[labl] |= 1<<(labc);
                    break;
                }
            }
        }
        for (int ii = 0; ii < aLen; ii++) {
            boolean hasEnd = false;
            for (int i = 0; i < 26; i++) {
                if(mapOut[i]==0&& has[i])
                {
                    ans.append((char)('a'+i));
                    while (mapIn[i]!=0) {
                        int j =Integer.numberOfTrailingZeros(mapIn[i]);
                        mapIn[i]^=(1<<j);
                        mapOut[j]^=(1<<i);
                    }
                    hasEnd = true;
                    has[i] = false;
                    break;
                }
            }
            if(!hasEnd)
            {
                return "";
            }
        }
        return ans.toString();
    }
}
```