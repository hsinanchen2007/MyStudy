### 解题思路
此处撰写解题思路
括号匹配：如果原始字符串包含一对合法括号，则替换为空；递归地用子串继续比较，直到最后。
如果最后为空，说明原始字符串串为有效括号对，反之，则说明原始字符串包含无效括号。
### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if((s.contains("()")||s.contains("{}")||s.contains("[]"))) {
            return isValid(s.replace("()","").replace("[]","").replace("{}",""));
        } else {
            return "".equals(s);
        }
    }
}
```