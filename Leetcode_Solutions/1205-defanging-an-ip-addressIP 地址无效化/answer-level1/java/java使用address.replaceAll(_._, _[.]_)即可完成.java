### 解题思路
执行用时 :5 ms, 在所有 Java 提交中击败了8.36% 的用户
内存消耗 :41.1 MB, 在所有 Java 提交中击败了5.29%的用户

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        return address.replaceAll("\\.", "[.]");
    }
}
```