### 解题思路
按序比较每个字符是否是子串（这里的题意：删除部分字符，所以子串的相对排序不能变。）
符合条件就进行比较。得出符合的解

### 代码

```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        int max = 0;
        String maxStr = "";
        for(int i = 0; i < d.size(); ++i) {
            String temp = d.get(i);
            if (temp.length() < max) continue; //如果该串比之前获取到的最大符合串的长度小，直接跳过。
            int index = 0;
            for (int j = 0; j < s.length(); ++j) {
                if (temp.charAt(index) == s.charAt(j)) {
                    if (index == temp.length() - 1) { //符合条件，进行比较。
                        if (temp.length() > maxStr.length()) {
                            maxStr = temp;
                            max = temp.length();
                        } else {
                            maxStr = maxStr.compareTo(temp) < 0 ? maxStr : temp;
                        }
                        break;
                    }
                    ++index;
                }
            }
        }
        return maxStr;
    }
}
```