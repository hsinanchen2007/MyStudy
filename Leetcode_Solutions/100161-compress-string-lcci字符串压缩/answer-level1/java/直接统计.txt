### 解题思路
![企业微信截图_a534de76-7b05-4bf0-a936-c0f7f17ef7fe.png](https://pic.leetcode-cn.com/fd03ddfa4a8037cddde01f34c57193e7cf3c9ab40c77c65c40839bbc39e55c3a-%E4%BC%81%E4%B8%9A%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_a534de76-7b05-4bf0-a936-c0f7f17ef7fe.png)
直接统计，看代码吧

### 代码

```java
class Solution {
    public String compressString(String S) {
        //特例
        if (S.length() < 2) {
            return S;
        }
        int len = S.length();
        int currLen = 1;
        
        //构造字符串
        StringBuilder sb = new StringBuilder();
        sb.append(S.charAt(0));

        for (int i = 1; i < len; i++) {
            if (S.charAt(i) == S.charAt(i-1)) {
                currLen++;
            } else {
                sb.append(currLen);
                sb.append(S.charAt(i));
                currLen = 1;
            }
        }

        //最后的尾值
        sb.append(currLen);

        String str = sb.toString();

        return str.length() >= len ? S : str;
    }
}
```