### 解题思路
1. 直接调用`replace()`方法

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        
        return address.replace(".", "[.]");
    }
}
```