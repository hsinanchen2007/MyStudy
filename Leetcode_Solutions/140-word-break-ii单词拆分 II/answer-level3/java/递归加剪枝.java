### 解题思路
暴力遍历求解。每次从字符串的头部去匹配，只有当有prefix在wordDict中才是合法的，否则就无法匹配。 拆分后递归剩余postfix。

### 代码

```java
class Solution {
     Map<String,List<String>> cuttingCache = new HashMap<>();
    /**
     * s--> 拆分成prefix s.subString(prefix.length())
     */
    public List<String> wordBreak(String s, List<String> wordDict) {

        List<String> cuttingResult = cuttingCache.get(s);
        if (cuttingResult != null) {
            return cuttingResult;
        }

        List<String> result = new ArrayList<>();
        for (String prefix : wordDict) {

            if (!s.startsWith(prefix)) {
                continue;
            }

            String left = s.substring(prefix.length());
            if (left.length() == 0) {
                result.add(prefix);
                continue;
            }

            List<String> childResult = wordBreak(left, wordDict);
            if (childResult == null) {
                continue;
            }
            for (String child : childResult) {
                result.add(prefix + " " + child);
            }
        }
        cuttingCache.put(s,result);
        return result;
    }

}
```