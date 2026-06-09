### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        String a=address.replace(".","[.]");
        return a;
    }
}

```