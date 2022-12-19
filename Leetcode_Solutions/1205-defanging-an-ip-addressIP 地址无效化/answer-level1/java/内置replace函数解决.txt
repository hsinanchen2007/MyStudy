### 解题思路
Java内置函数直接解决

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
            return address.replace(".","[.]" );
    }
}
```