### 解题思路
调用函数一步完成，写代码确实比C舒服多了...

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}
```