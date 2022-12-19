### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ec47ac787a540b78022396b4bb1a68b8fe608854059761c286d331e6577e1af7-image.png)
利用StringBuilder来对字符串进行拼接
### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)==' '){
                res.append('%');
                res.append('2');
                res.append('0');
            }
            else
                res.append(s.charAt(i));
        }
        return res.toString();
    }
}
```