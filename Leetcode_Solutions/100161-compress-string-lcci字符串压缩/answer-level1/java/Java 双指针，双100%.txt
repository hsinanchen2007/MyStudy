### 解题思路
直接上代码吧。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S == null || S.length() <= 1) {
            return S;
        }
        StringBuffer res = new StringBuffer();
        char[] items = S.toCharArray();
        int l = 0, r = 0;
        while (r < items.length) {
            while(r < items.length && items[l] == items[r])
                r ++;
            res.append(items[l]).append(r - l);
            l = r;
        }
        return res.length() >= items.length ? S : res.toString();
    }
}
```