### 解题思路
因为IPV4一共就包含0-255，IPV6一共就包含0-FFFF。
所以三行if else就可以啦。
哇哈哈哈哈。

### 代码

```java
class Solution {
    public String validIPAddress(String IP) {
        if(IP.matches("((2[0-5][0-5]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(2[0-5][0-5]|1[0-9][0-9]|[1-9][0-9]|[0-9])")) return "IPv4";
		else if(IP.matches("(([0-9]|[a-f]|[A-F]){1,4}:){7}(([0-9]|[a-f]|[A-F]){1,4})")) return "IPv6";
		else return "Neither";
    }
}
```