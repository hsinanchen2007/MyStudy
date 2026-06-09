### 解题思路

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        StringBuilder builderA = new StringBuilder();
        StringBuilder builderB = new StringBuilder();
        for (char c : S.toCharArray()) {
            if (c != '#') {
                builderA.append(c);
            } else if (builderA.length() > 0) {
                builderA.deleteCharAt(builderA.length() - 1);
            }
        }
        for (char c : T.toCharArray()) {
            if (c != '#') {
                builderB.append(c);
            } else if (builderB.length() > 0) {
                builderB.deleteCharAt(builderB.length() - 1);
            }
        }
        return builderA.toString().equals(builderB.toString());
    }
}
```