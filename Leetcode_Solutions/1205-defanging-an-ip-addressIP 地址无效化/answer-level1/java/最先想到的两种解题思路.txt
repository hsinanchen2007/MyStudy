### 解题思路
1.String类replace()
2.正则表达式replaceAll()

### 代码

#### 解题方式一 [效率高]
``` java
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".","[.]");
    }
}
```
#### 解题方式二
```java
class Solution {
    public String defangIPaddr(String address) {
        return address.replaceAll("\\.+","[.]");
    }
}
```