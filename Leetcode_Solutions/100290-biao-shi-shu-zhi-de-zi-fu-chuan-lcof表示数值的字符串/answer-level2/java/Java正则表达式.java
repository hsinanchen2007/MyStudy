### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isNumber(String s) {
        String str="^[+|-]?((\\d+\\.?)|(\\d*\\.\\d+))([E|e][+|-]?\\d+)?$";
        return s.trim().matches(str);
    }
}
```