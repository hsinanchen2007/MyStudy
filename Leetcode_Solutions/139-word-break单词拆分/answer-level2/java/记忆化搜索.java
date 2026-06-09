### 解题思路
并没有想出dp解法，用了记忆化搜索，存储前i个元素是否可以拆分

### 代码

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        // 每次搜索前i个字符是否可分解
        boolean[] p = new boolean[s.length()+1];
        p[0] = true;
        for (int i=0;i<s.length();i++) {
            for (int j=i;j>=0;j--) {
                if (wordDict.contains(s.substring(j, i+1)) && p[j]) {
                    p[i+1] = true;
                    System.out.println(i+1 + ":" + p[i+1]);
                    break;
                }
                if (j == 0) {      
                    p[i+1] = false;
                    System.out.println(i+1 + ":" + p[i+1]);
                }
            }  
        }
        return p[s.length()];
    }
}
```