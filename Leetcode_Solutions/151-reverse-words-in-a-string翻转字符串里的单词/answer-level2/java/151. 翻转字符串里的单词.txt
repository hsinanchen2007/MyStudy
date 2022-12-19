### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] sArray = s.split(" +");
        String ans = "";
        for (int i = sArray.length - 1; i >= 0; i--) {
            ans += sArray[i] + " ";
        }
        return ans.trim();
    }
}
```